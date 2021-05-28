#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    int n,m;
    while(scanf("%d %d",&n,&m) == 2)
    {
        if(!n && !m)
            break;
        int i,j,u,v,cnt;
        int ans[105];
        int in[105] = {};
        vector<int> adj[105];
        queue<int> q;

        cnt = 0;
        while(m--)
        {
            scanf("%d %d",&u,&v);
            adj[u].push_back(v);
            in[v]++;
        }

        for(i = 1; i <= n; i++)
            if(!in[i])
                q.push(i);

        while(!q.empty())
        {
            u = q.front();
            q.pop();
            ans[cnt++] = u;
            for(i = 0; i < (int)adj[u].size(); i++)
            {
                v = adj[u][i];
                if(--in[v] == 0)
                    q.push(v);
            }
        }

        for(i = 0; i < cnt; i++)
            printf("%d%s",ans[i],(i != cnt) ? " " : "");
        putchar('\n');
    }
    return 0;    
}
