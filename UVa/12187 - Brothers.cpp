#include <cstdio>
#include <cstring>
using namespace std;
int N,R,C,K;
int grid[105][105],tmp[105][105];
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

void go()
{
    int x,y,z;
    memcpy(tmp,grid,sizeof(grid));

    for(x = 0; x < R; x++)
        for(y = 0; y < C; y++)
            for(z = 0; z < 4; z++)
            {
                int nx = x+dx[z]; int ny = y+dy[z];
                if(nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
                if(tmp[nx][ny] == ((tmp[x][y]+1)%N)) grid[nx][ny] = tmp[x][y];
            }
}

int main()
{
    while(scanf("%d %d %d %d",&N,&R,&C,&K) == 4)
    {
        if(!N) break;
        int i,j;
        for(i = 0; i < R; i++)
            for(j = 0; j < C; j++)
                scanf("%d",&grid[i][j]);
        
        while(K--)
            go();
        
        for(i = 0; i < R; i++)
            for(j = 0; j < C; j++)
                printf("%d%c",grid[i][j],(j < C-1) ? ' ' : '\n');
    }
    return 0;   
}
