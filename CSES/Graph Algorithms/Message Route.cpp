#include <cstdio>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;
int n,m;
int dis[100005];
int p[100005];
vector<int> adj[100005];

void path(int u)
{
    if(u == 1)
    {
        printf("1 ");
        return;
    }
    path(p[u]);
    printf("%d ",u);
}

void bfs()
{
    queue<int> q;
    memset(dis,-1,sizeof(dis));

    q.push(1);
    dis[1] = 0;
    p[1] = -1;

    while(!q.empty())
    {
        int u = q.front(); q.pop();

        for(int i = 0; i < (int)adj[u].size(); ++i)
        {
            int v = adj[u][i];

            if(dis[v] != -1) continue;
            dis[v] = dis[u]+1;
            p[v] = u;
            q.push(v);
        }
    }
}

int main()
{
    scanf("%d %d",&n,&m); int u,v;
    while(m--)
    {
        scanf("%d %d",&u,&v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bfs();
    if(dis[n] == -1) puts("IMPOSSIBLE");
    else
    {
        int t = n;
        printf("%d\n",dis[n]+1);
        path(n);
    }

    return 0;   
}
