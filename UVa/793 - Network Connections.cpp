#include <cstdio>
using namespace std;
int t,n;
struct Disjoint{
    int p[100001],r[100001];
    void init(int n)
    {
        for(int i = 1; i <= n; i++)
        {
            p[i] = i;
            r[i] = 1;
        }
    }

    int find(int u)
    {
        if(u == p[u]) return u;
        return p[u] = find(p[u]);
    }

    int merge(int u,int v)
    {
        u = find(u); v = find(v);
        if(u == v) return 0;
        if(r[u] > r[v])
        {
            p[v] = u;
            r[u] += r[v];
        }
        else
        {
            p[u] = v;
            r[v] += r[u];
        }

        return 1;
    }

};

int main()
{
    scanf("%d",&t);
    while(t--)
    {   
        scanf("%d",&n);
        Disjoint a;
        a.init(n);
        getchar(); char str[100];
        char c; int u,v; int s = 0, us = 0;
        while(gets(str))
        {
            if(str[0] == '\0') break;
            sscanf(str,"%c %d %d",&c,&u,&v);
            if(c == 'c') a.merge(u,v);
            else
            {
                int ret = a.find(v) == a.find(u);
                if(ret == 1) s++;
                else us++;
            }
        }
        printf("%d,%d\n",s,us);
        if(t) puts("");
    }
    return 0;
}
