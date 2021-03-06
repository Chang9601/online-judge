#include <cstdio>
using namespace std;
int n,m;
char grid[1005][1005];
bool vis[1005][1005];
int ans;

void dfs(int x,int y)
{
    if(x < 0 || x >= n || y < 0 || y >= m) return;
    if(vis[x][y] || grid[x][y] != '.') return; 
    vis[x][y] = true;

    dfs(x-1,y);
    dfs(x+1,y);
    dfs(x,y-1);
    dfs(x,y+1);
}

int main()
{
    scanf("%d %d",&n,&m); int i,j;
    for(i = 0; i < n; i++) scanf("%s",grid[i]);

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            if(!vis[i][j] && grid[i][j] == '.')
            {
                ans++;
                dfs(i,j);
            }
        }
    }

    printf("%d\n",ans);

    return 0;   
}
