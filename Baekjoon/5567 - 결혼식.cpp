#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;
int n,m;
vector<int> adj[505];
int dis[505];

void bfs(int s)
{
    int u,v; memset(dis,-1,sizeof(dis));
    dis[s] = 0; queue<int> q;
    q.push(s);

    while(!q.empty())
    {
        u = q.front(); q.pop();

        for(int i = 0; i < (int)adj[u].size(); i++)
        {
            v = adj[u][i];
            if(dis[v] != -1) continue;
            dis[v] = dis[u]+1;
            q.push(v);
        }     
    }
}

int main()
{   
    int i,j; int u,v; scanf("%d %d",&n,&m);
    for(i = 0; i < m; i++)
    {  
        scanf("%d %d",&u,&v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dis[1] = 0; int ans = 0; 
    bfs(1);
    for(i = 2; i <= n; i++)
        if(dis[i] != -1 && dis[i] <= 2) ans++;
    
    printf("%d\n",ans);
    return 0;
}
