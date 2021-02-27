#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;
int L,R,C;
char grid[35][35][35];
int dis[35][35][35];
int dz[6] = {-1,1,0,0,0,0};
int dx[6] = {0,0,-1,1,0,0};
int dy[6] = {0,0,0,0,-1,1};
struct Point{
    int z,x,y;
};

int main()
{   
    while(scanf("%d %d %d",&L,&R,&C) == 3)
    {
        if(!L && !R && !C) break;
        memset(dis,-1,sizeof(dis)); int i,j,k;
        int sz,sx,sy,ez,ex,ey; int z,x,y,nz,nx,ny;

        for(i = 0; i < L; i++)
            for(j = 0; j < R; j++)
                scanf("%s",grid[i][j]);
        
        for(i = 0; i < L; i++)
            for(j = 0; j < R; j++)
                for(k = 0; k < C; k++)
                {
                    if(grid[i][j][k] == 'S')
                    {
                        sz = i;
                        sx = j;
                        sy = k;
                    }
                    else if(grid[i][j][k] == 'E')
                    {
                        ez = i;
                        ex = j;
                        ey = k;
                    }
                }

        queue<Point> q; 
        q.push({sz,sx,sy});
        dis[sz][sx][sy] = 0;
        
        while(!q.empty())
        {
            z = q.front().z; 
            x = q.front().x; y = q.front().y;
            q.pop();

            for(i = 0; i < 6; i++)
            {
                nz = z+dz[i]; 
                nx = x+dx[i]; ny = y+dy[i];

                if(nz < 0 || nz >= L || nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
                if(dis[nz][nx][ny] != -1 || grid[nz][nx][ny] == '#')  continue;
                dis[nz][nx][ny] = dis[z][x][y]+1;
                q.push({nz,nx,ny});
            }
        }

        int ans = dis[ez][ex][ey];
        if(ans == -1) puts("Trapped!");
        else printf("Escaped in %d minute(s).\n",ans);
    }
    return 0;
}
