#include <iostream>
#include <set>
using namespace std;
int n,m;
set<int> s;
int ans[100005];
struct DSU{
    int p[100005],r[100005];
 
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
 
        if(r[v] > r[u])
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
 
int main()
{
    scanf("%d %d",&n,&m); int i; int u,v,size,cnt = 0;
    DSU A; A.init(n);
 
    for(i = 0; i < m; i++)
    {
        scanf("%d %d",&u,&v);
        A.merge(u,v);
    }
 
    for(i = 1; i <= n; i++)
    {
        u = A.find(i);
        s.insert(u);
    }
    size = (int)s.size()-1;
    for(set<int>::iterator it = s.begin(); it != s.end(); it++)
            ans[cnt++] = *it;
 
    printf("%d\n",size);
    for(i = 0; i < cnt-1; i++) printf("%d %d\n",ans[i],ans[i+1]);
    return 0;   
}
