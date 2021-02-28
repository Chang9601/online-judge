#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;
int T,N,M;
char grid[105][105];
int dis[105][105];
int hx[8] = {-2,-2,-1,-1,1,1,2,2};
int hy[8] = {-1,1,-2,2,-2,2,-1,1};
int kx[8] = {-1,-1,-1,0,0,1,1,1};
int ky[8] = {-1,0,1,-1,1,-1,0,1};
struct Point{
    int x,y;
};

int main()
{  
    scanf("%d",&T);
    while(T--)
    {
        int i,j,k; int x,y,nx,ny,ex,ey; queue<Point> q;
        scanf("%d %d",&N,&M); memset(dis,-1,sizeof(dis));
        for(i = 0; i < N; i++) scanf("%s",grid[i]); int sx,sy;

        for(i = 0; i < N; i++)
        {
            for(j = 0; j < M; j++)
            {
                if(grid[i][j] == 'Z')
                {
                    for(k = 0; k < 8; k++)
                    {
                        x = i+hx[k]; y = j+hy[k];

                        if(x >= 0 && x < N && y >= 0 && y < M)
                        {
                            if(grid[x][y] == '.') grid[x][y] = 'X';
                        }
                    }
                }
                else if(grid[i][j] == 'A')  
                {
                    sx = i; sy = j;
                }
                else if(grid[i][j] == 'B')
                {
                    ex = i; ey = j;
                }
            }
        }

        q.push({sx,sy});
        dis[sx][sy] = 0;

        while(!q.empty())
        {
            x = q.front().x; y = q.front().y;
            q.pop();

            for(i = 0; i < 8; i++)
            {
                nx = x+kx[i]; ny = y+ky[i];

                if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
                if(grid[nx][ny] == 'Z' || grid[nx][ny] == 'X' || dis[nx][ny] != -1) continue;

                q.push({nx,ny});
                dis[nx][ny] = dis[x][y]+1;
            }
        }

        if(dis[ex][ey] == -1) puts("King Peter, you can't go now!");
        else printf("Minimal possible length of a trip is %d\n",dis[ex][ey]);
    }

    return 0;
}
