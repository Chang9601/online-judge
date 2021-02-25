#include <cstdio>
#include <cstring>
#include <cctype>
using namespace std;
char grid[105][105];
int collected[105][105];
int n,m,s;
char cm[50005];

int main()
{   
    while(scanf("%d %d %d",&n,&m,&s) == 3)
    {
        if(!n && !m && !s) break;
        int ans = 0; memset(collected,0,sizeof(collected));
        int x,y,d;
      //  getchar();
        for(int i = 0; i < n; i++)
        {
            scanf("%s",grid[i]);
            for(int j = 0; grid[i][j]; j++)
            {
                if(isalpha(grid[i][j]))
                {
                    switch(grid[i][j])
                    {
                        case 'N': d = 0; break;
                        case 'S': d = 2; break;
                        case 'L': d = 1; break;
                        case 'O': d = 3; break;
                    }
                    x = i; y = j;
                }
            }
        }

        scanf("%s",cm);
        for(int i = 0; i < s; i++)
        {
            if(cm[i] == 'D') d = (d+1)%4;
            else if(cm[i] == 'E') d = (d+4-1)%4;
            else
            {
                if(d == 0)
                {
                    if(x-1 < 0 || grid[x-1][y] == '#') continue;
                    else --x;
                }
                else if(d == 1)
                {
                    if(y+1 >= m || grid[x][y+1] == '#') continue;
                    else ++y;
                }
                else if(d == 2)
                {
                    if(x+1 >= n || grid[x+1][y] == '#') continue;
                    else ++x;
                }
                else
                {
                    if(y-1 < 0 || grid[x][y-1] == '#') continue;
                    else --y;                     
                }

                if(grid[x][y] == '*')
                {
                    if(collected[x][y]) continue;
                    else
                    {
                        collected[x][y] = 1;
                        ans++;
                    }
                }    
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
