#include <cstdio>
#include <cmath>
using namespace std;
struct DSU{
    int p[100005],r[100005];
    int N,mx = -1;
    
    void init(int n)
    {
        int i;
        for(i = 1; i <= n; i++)
        {
            p[i] = i;
            r[i] = 1;
        }
        N = n;
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

        if(r[u] < r[v])
        {
            r[v] += r[u];
            p[u] = v;
            mx = max(mx,r[v]);
        }
        else
        {
            r[u] += r[v];
            p[v] = u;
            mx = max(mx,r[u]);
        }
        N--;
        return 1;
    }

};
int n,m;

int main()
{  
    scanf("%d %d",&n,&m); int u,v,i,j;
    DSU A; A.init(n);
    while(m--)
    {
        scanf("%d %d",&u,&v);
        A.merge(u,v);
        printf("%d %d\n",A.N,A.mx);
    }
    return 0;
}
