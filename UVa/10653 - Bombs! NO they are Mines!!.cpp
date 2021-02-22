#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;
#define INF 999999999999
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};
int R,C,N;
int grid[1005][1005];
struct Point{
    int x,y;
};

int main()
{   
    while(scanf("%d %d",&R,&C) == 2)
    {
        if(!R && !C) break;
        int i,j,r,c,n; int sx,sy,ex,ey;

        int dis[1005][1005]; 
        memset(dis,-1,sizeof(dis)); memset(grid,0,sizeof(grid));
        queue<Point> q;

        scanf("%d",&N);
        for(i = 0; i < N; i++)
        {
            scanf("%d %d",&r,&n);

            for(j = 0; j < n; j++)
            {
                scanf("%d",&c);
                grid[r][c] = -1; // bombs
            }
        }

        scanf("%d %d",&sx,&sy); scanf("%d %d",&ex,&ey);
        q.push({sx,sy}); dis[sx][sy] = 0;

        while(!q.empty())
        {
            int x = q.front().x; int y = q.front().y;
            q.pop();

            for(i = 0; i < 4; i++)
            {
                int nx = x+dx[i]; int ny = y+dy[i];

                if(nx >= 0 && nx < R && ny >= 0 && ny < C && dis[nx][ny] == -1 && !grid[nx][ny])
                {
                    dis[nx][ny] = dis[x][y]+1;
                    q.push({nx,ny});
                }
            }
        }

        printf("%d\n",dis[ex][ey]);
    }
   
    return 0;
}
