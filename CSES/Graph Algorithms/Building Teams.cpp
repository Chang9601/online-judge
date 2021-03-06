#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
int n,m;
vector<int> adj[100005];
int dis[100005];
int A[100005];
bool ok;

void bfs(int s)
{
    queue<int> q;
    q.push(s);
    dis[s] = 0;
    A[s] = 1;

    while(!q.empty())
    {
        int u = q.front(); q.pop();
        for(int i = 0; i < (int)adj[u].size(); i++)
        {
            int v = adj[u][i];
            if(dis[v] == -1)
            {
                dis[v] = dis[u]+1;
                q.push(v);
                A[v] = (dis[v]%2) ? 2 : 1;
            }
            else if(A[v] == A[u]) 
            {
                ok = false;
                return;
            }
        }
    }
}

int main()
{
    scanf("%d %d",&n,&m); int i,j; int u,v;
    memset(dis,-1,sizeof(dis)); int cnt = 0;
    ok = true;

    for(i = 0; i < m; i++)
    {
        scanf("%d %d",&u,&v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(i = 1; i <= n; i++)
    {
        if(dis[i] != -1) continue;
        bfs(i); 
    }

    if(ok) for(i = 1; i <= n; i++) printf("%d ",A[i]);
    else puts("IMPOSSIBLE");

    return 0;   
}
