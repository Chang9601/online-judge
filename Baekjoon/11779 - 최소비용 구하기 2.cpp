#include <cstdio>
#include <vector>
#include <queue>
#define INF 1000000000
using namespace std;

int n,m;

int main()
{   

    scanf("%d %d",&n,&m); priority_queue<pair<int,int>> pq;
    vector<pair<int,int>> adj[1005]; int i,j; bool vis[1005] = {0,};
    int u,v,w,s,e; int p[1005]; int dis[1005]; int t,cnt = 0; int ans[1005];

    for(i = 1; i <= n; i++) dis[i] = INF;
    for(i = 0; i < m; i++)
    {
        scanf("%d %d %d",&u,&v,&w);
        adj[u].push_back({v,w});
    }

    scanf("%d %d",&s,&e);

    dis[s] = 0; p[s] = -1;
    pq.push({0,s});

    while(!pq.empty())
    {
        u = pq.top().second; pq.pop();

        if(vis[u]) continue;
        vis[u] = true;

        for(i = 0; i < (int)adj[u].size(); i++)
        {
            v = adj[u][i].first; w = adj[u][i].second;

            if(w+dis[u] < dis[v])
            {
                dis[v] = w+dis[u];
                pq.push({-dis[v],v});
                p[v] = u;
            }
        }
    }

    t = e;
    ans[cnt++] = e;
    while(t != s)
    {
        ans[cnt++] = p[t];
        t = p[t];
    }
    ans[cnt] = s;

    printf("%d\n",dis[e]);
    printf("%d\n",cnt);
    for(i = cnt-1; i >= 0; i--) printf("%d ",ans[i]);

    return 0;
}
