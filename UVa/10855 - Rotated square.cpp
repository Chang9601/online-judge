#include <cstdio>
#include <cstring>
using namespace std;
char grid[505][505],piece[505][505],tmp[505][505];
int N,n;

void rotate()
{  
    int i,j;

    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            tmp[i][j] = piece[n-1-j][i];
    memcpy(piece,tmp,sizeof(tmp));
}

bool fit(int x,int y)
{
    int i,j;
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            if(grid[x+i][y+j] != piece[i][j]) return false;
    return true;
}

int main()
{  
    while(scanf("%d %d",&N,&n) == 2)
    {
        if(!N && !n) break;
        int r[4] = {};
        int i,j,k,num;

        for(i = 0; i < N; i++) scanf("%s",grid[i]);
        for(i = 0; i < n; i++) scanf("%s",piece[i]);

        for(i = 0; i < 4; i++)
        {
            num = 0;
            for(j = 0; j <= N-n; j++)
                for(k = 0; k <= N-n; k++)
                    num += fit(j,k);
            r[i] = num;
            rotate();
        }

        printf("%d %d %d %d\n",r[0],r[1],r[2],r[3]);
    }
    return 0;
}
