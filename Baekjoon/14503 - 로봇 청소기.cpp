#include <cstdio>
using namespace std;
#undef S
int N,M;
bool vis[55][55];
int grid[55][55];
int r,c,d;

bool is_back_not_wall()
{
    bool ans = false;
    switch(d)
    {
        case 0:
            if(r+1 < N && !grid[r+1][c])
            {
                r++;
                ans = true;
            }
            break;
        case 1: 
            if(c-1 >= 0 && !grid[r][c-1])
            {
                c--;
                ans = true;
            }
            break;
        case 2:
            if(r-1 >= 0 && !grid[r-1][c])
            {
                r--;
                ans = true;
            }
            break; 
        case 3:
            if(c+1 < M && !grid[r][c+1])
            {
                c++;
                ans = true;
            }
            break;
    }
    return ans;
}

int main()
{   
    scanf("%d %d",&N,&M);
    scanf("%d %d %d",&r,&c,&d);
    int i,j,ans = 0;
    for(i = 0; i < N; i++)
        for(j = 0; j < M; j++)
            scanf("%d",&grid[i][j]);
    
    bool run = true; bool ok;
    vis[r][c] = true;
    while(run)
    {
        int t = d;
        for(i = 0; i < 4; i++)
        {
            ok = false;
            t = (t+4-1)%4;

            switch(t)
            {
                case 0:
                    if(r-1 >= 0 && !vis[r-1][c] && !grid[r-1][c])
                    {
                        r--;
                        ok = true;
                    }
                    break;
                case 1:
                    if(c+1 < M && !vis[r][c+1] && !grid[r][c+1])
                    {
                        c++;
                        ok = true;
                    }
                    break;
                case 2:
                    if(r+1 < N && !vis[r+1][c] && !grid[r+1][c])
                    {
                        r++;
                        ok = true;
                    }
                    break;
                case 3:
                    if(c-1 >= 0 && !vis[r][c-1] && !grid[r][c-1])
                    {
                        c--;
                        ok = true;
                    }
                    break;
            }
            if(ok) break;
        }

        if(ok) 
        {
            d = t;
            vis[r][c] = true;
        }
        else
        {
            if(is_back_not_wall());
            else run = false;
        }
    }

    for(i = 0; i < N; i++)
        for(j = 0; j < M; j++)
            ans += vis[i][j];
    printf("%d\n",ans);

    return 0;
}
