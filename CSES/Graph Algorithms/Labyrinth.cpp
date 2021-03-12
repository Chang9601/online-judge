#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
int n,m;
int dis[1005][1005];
char grid[1005][1005];
char path[1005][1005];
int p[1005][1005];
int sx,sy,ex,ey;
struct Point{
    int x,y;
};
int dx[] = {-1,0,1,0}; 
int dy[] = {0,1,0,-1};

int main()
{
    scanf("%d %d",&n,&m); int i,j,x,y,nx,ny; 
    memset(dis,-1,sizeof(dis)); queue<Point> q;

    for(i = 0; i < n; i++)
    {
        scanf("%s",grid[i]);
        for(j = 0; grid[i][j]; j++)
        {
            if(grid[i][j] == 'A')
            {
                sx = i;
                sy = j;
            }
            else if(grid[i][j] == 'B')
            {
                ex = i;
                ey = j;
            }
        }
    }
  
    dis[sx][sy] = 0;
    q.push({sx,sy});
    while(!q.empty())
    {
        x = q.front().x; y = q.front().y;
        q.pop();
        if(x == ex && y == ey) break;

        for(i = 0; i < 4; i++)
        {
            nx = x+dx[i]; ny = y+dy[i];

            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(dis[nx][ny] != -1 || grid[nx][ny] == '#') continue;

            q.push({nx,ny});
            dis[nx][ny] = dis[x][y]+1;
            p[nx][ny] = x*m+y;  
            if(i == 0) path[nx][ny] = 'U';
            else if(i == 1) path[nx][ny] = 'R';
            else if(i == 2) path[nx][ny] = 'D';
            else if(i == 3) path[nx][ny] = 'L';
        }
    }

    if(dis[ex][ey] == -1) puts("NO");
    else
    {
        int t = ex*m+ey; char A[1005*1005] = {};
        int cnt = 0;
        while(t != sx*m+sy)
        {
            A[cnt++] = path[t/m][t%m];
            t = p[t/m][t%m];
        }
        A[cnt] = '\0';
        
        puts("YES");
        printf("%d\n",dis[ex][ey]);
        for(i = cnt-1; i >= 0; i--) putchar(A[i]);
    }
    
    return 0;   
}
