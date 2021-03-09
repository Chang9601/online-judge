#include <cstdio>
using namespace std;
int N,M;

struct DSU{
    int p[1005],r[1005];

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
        if(u == p[u]) return u;
        return p[u] = find(p[u]);
    }

    int merge(int u,int v)
    {
        u = find(u); v = find(v);
        if(u == v) return 0;

        if(r[v] < r[u])
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
    scanf("%d %d",&N,&M); int i; int u,v,ans; DSU A;
    ans = N; A.init(N);

    for(i = 0; i < M; i++)
    {
        scanf("%d %d",&u,&v);
        ans -= A.merge(u,v);
    }

    printf("%d\n",ans);
    return 0;
}

