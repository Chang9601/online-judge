#include <cstdio>
#include <cstring>
using namespace std;
char grid[105][105];
bool vis[105][105];

void dfs(int x,int y,int N)
{
    if(x < 0 || x >= N || y < 0 || y >= N)
        return;
    if(vis[x][y] || grid[x][y] == '.')
        return;
    
    vis[x][y] = true;
    dfs(x-1,y,N);
    dfs(x+1,y,N);
    dfs(x,y-1,N);
    dfs(x,y+1,N);
}

int main()
{
    int T,N;
    int i,j,idx,ans;
    scanf("%d",&T);

    idx = 1;
    while(T--)
    {
        scanf("%d",&N);
        ans = 0;

        for(i = 0; i < N; i++)
            scanf("%s",grid[i]);
        memset(vis,false,sizeof(vis));

        for(i = 0; i < N; i++)
            for(j = 0; j < N; j++)
            {
                if(!vis[i][j] && grid[i][j] == 'x')
                {
                    ans++;
                    dfs(i,j,N);
                }
            }
        printf("Case %d: %d\n",idx++,ans);
    }

    return 0;    
}
