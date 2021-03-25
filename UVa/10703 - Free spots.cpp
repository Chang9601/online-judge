#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int W,H,N;
bool grid[505][505];

int main()
{
    while(scanf("%d %d %d",&W,&H,&N) == 3)
    {
        if(!W && !H && !N) break;
        memset(grid,false,sizeof(grid));
        int lx,ly,rx,ry; int i,j;
        int ans = 0;

        while(N--)
        {
            scanf("%d %d %d %d",&lx,&ly,&rx,&ry);

            if(lx > rx) swap(lx,rx);
            if(ly > ry) swap(ly,ry);
            
            for(i = ly; i <= ry; i++)
                for(j = lx; j <= rx; j++)
                    grid[i][j] = true;
        }

        for(i = 1; i <= H; i++)
            for(j = 1; j <= W; j++)
                ans += !grid[i][j] ? 1 : 0;
        
        if(!ans) puts("There is no empty spots.");
        else if(ans == 1) puts("There is one empty spot.");
        else printf("There are %d empty spots.\n",ans);

    }
    return 0;   
}

