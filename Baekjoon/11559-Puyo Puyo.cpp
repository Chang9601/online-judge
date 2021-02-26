#include <cstdio>
#include <cstring>
using namespace std;
char grid[15][8];
int A[100];
bool vis[15][8];
int r = 12,c = 6;
int area;

void dfs(int x,int y,char s)
{
    if(x < 0 || x >= r || y < 0 || y >= c) return;
    if(vis[x][y] || grid[x][y] != s) return;

    A[area] = c*x+y;
    vis[x][y] = true;
    area++;

    dfs(x-1,y,s);
    dfs(x+1,y,s);
    dfs(x,y-1,s);
    dfs(x,y+1,s);
}

void run()
{
    int i,x,y;
    for(i = 0; i < area; i++)
    {
        x = A[i]/c; y = A[i]%c;
        grid[x][y] = '.';
    }
}

void update()
{
    int i,j,k;

    for(j = 0; j < c; j++)
    {
        for(i = r-1; i >= 0; i--)
        {
            if(grid[i][j] != '.')
            {
                for(k = i+1; k < r && (grid[k][j] == '.'); k++);
                if(k == i+1) continue; // 주의
                grid[k-1][j] = grid[i][j];
                grid[i][j] = '.';       
            }
        }
    }
}

int main()
{   
    int ans = 0; int i,j;
    for(i = 0; i < r; i++)
            scanf("%s",grid[i]);

    while(1)
    {
        bool ok = false;
        memset(vis,false,sizeof(vis));

        for(i = r-1; i >= 0; i--)
        {
            for(j = 0; j < c; j++)
            {
                if(grid[i][j] != '.' && !vis[i][j])
                {
                    area = 0;
                    dfs(i,j,grid[i][j]);
                    if(area >= 4)
                    {
                        run();
                        ok = true;
                    }
                }
            }
        }

        if(!ok) break;
        ans++;
        update();

      //  for(i = 0; i < r; i++,puts(""))
         //   for(j = 0; j < c; j++)
           //     printf("%c",grid[i][j]);
    }    

    printf("%d\n",ans);

    return 0;
}
