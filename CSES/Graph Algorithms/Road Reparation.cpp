#include <cstdio>
#include <algorithm>
using namespace std;
int n,m;
struct Point{
    int u,v;
    long long c;
};
Point A[200005];
struct DSU{
    int p[100005],r[100005];

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

        if(r[u] < r[v])
        {
            r[v] += r[u];
            p[u] = v;
        }
        else
        {
            r[u] += r[v];
            p[v] = u;
        }
        return 1;
    }
};
bool cmp(const Point &a,const Point &b)
{
    return a.c < b.c;
}

int main()
{
    int i,u,v,cnt; long long c,ans = 0;
    DSU D;
    scanf("%d %d",&n,&m);
    D.init(n);

    for(i = 0; i < m; i++)
    {
        scanf("%d %d %lld",&u,&v,&c);
        A[i].u = u; A[i].v = v;
        A[i].c = c;
    }

    sort(A,A+m,cmp);
    for(i = 0; i < m; i++)
        if(D.merge(A[i].u,A[i].v)) ans += A[i].c;
    cnt = D.r[D.find(1)];

    if(cnt != n) puts("IMPOSSIBLE");
    else printf("%lld\n",ans);
    return 0;   
}
