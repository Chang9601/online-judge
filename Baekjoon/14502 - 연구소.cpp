#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
int N,M;
int grid[10][10];
int tmp[10][10];
bool vis[10][10];
bool chosen[70];
int A[70];
struct Point{
    int x,y;
};
Point V[70];
int num;
int ans;

void dfs(int x,int y)
{
    if(x < 0 || x >= N || y < 0 || y >= M) return;
    if(vis[x][y] || tmp[x][y] == 1) return;
    vis[x][y] = true;

    dfs(x-1,y);
    dfs(x+1,y);
    dfs(x,y-1);
    dfs(x,y+1);
}

int run()
{
    int i,j; int x,y; int sum = 0;
    memset(vis,false,sizeof(vis));
    memcpy(tmp,grid,sizeof(grid));

    for(i = 0; i < 3; i++)
    {
        x = A[i]/M; y = A[i]%M;
        tmp[x][y] = 1;
    }

    for(i = 0; i < num; i++)
        dfs(V[i].x,V[i].y);

    for(i = 0; i < N; i++)
        for(j = 0; j < M; j++) 
            sum += (!vis[i][j] && !tmp[i][j]) ? 1 : 0;
    return sum;
}

void go(int cnt,int idx)
{
    if(cnt == 3)
    {   
        int t = run();
        ans = max(ans,t);
        return;
    }

    for(int i = idx; i < N*M; i++)
    {
        int x = i/M; int y = i%M;
        if(grid[x][y] != 0) continue;
        if(chosen[i]) continue;
        chosen[i] = true;
        A[cnt] = i;
        go(cnt+1,i);
        chosen[i] = false;
    }
}

int main()
{
    scanf("%d %d",&N,&M); int i,j;
    num = 0;
    for(i = 0; i < N; i++)
    {
        for(j = 0; j < M; j++)
        {
            scanf("%d",&grid[i][j]);
            if(grid[i][j] == 2)
            {
                V[num].x = i; V[num].y = j;
                num++;
            }
        }
    }

    ans = -10;
    go(0,0);
    printf("%d\n",ans);
    return 0;   
}
