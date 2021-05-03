#include <cstdio>
using namespace std;
int T;
struct DSU{
    int p[100001],r[100001];

    void init(int n)
    {
        int i;
        for(i = 1; i <= n; i++)
        {
            p[i] = i;
            r[i] = 1;
        }
    }

    int find(int u)
    {
        if(u == p[u])
            return u;
        return p[u] = find(p[u]);
    }

    int merge(int u,int v)
    {
        u = find(u); v = find(v);

        if(u == v)
            return 0;

        if(r[v] < r[u])
        {
            r[u] += r[v];
            p[v] = u;
        }
        else
        {
            r[v] += r[u];
            p[u] = v;
        }
        return 1;
    }
};

void deleteNewline(char str[])
{
    int i = 0;
    while(str[i] != '\n')
        i++;
    str[i] = '\0';
}

void clearInputBuffer()
{
    while(getchar() != '\n')
        ;
}

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        int n;
        scanf("%d",&n);
        clearInputBuffer();
        char str[100];
        DSU d; d.init(n);
        char c;
        int u,v,s,us;
        s = us = 0;

        while(fgets(str,sizeof(str),stdin))
        {
            deleteNewline(str);
            if(str[0] == '\0')
                break;
            sscanf(str,"%c %d %d",&c,&u,&v);
            if(c == 'c')
                d.merge(u,v);
            else
            {
                u = d.find(u); v = d.find(v);
                if(u == v)
                    s++;
                else 
                    us++;
            }
        }
        printf("%d,%d\n",s,us);
        if(T) 
            puts("");
    }
    return 0;    
}
