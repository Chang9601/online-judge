#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
    int M;
    char grid[105][105];

    while(scanf("%d",&M) == 1)
    {
        int i,j,k,l;
        int mn,ans,ret;

        for(i = 0; i < M; i++)
            scanf("%s",grid[i]);

        ans = -1;
        for(i = 0; i < M; i++)
        {
            for(j = 0; j < M; j++)
            {
                mn = 1e9;
                if(grid[i][j] == '1')
                {
                    for(k = 0; k < M; k++)
                    {
                        for(l = 0; l < M; l++)
                        {
                            if(grid[k][l] == '3')
                            {
                                ret = abs(i-k)+abs(j-l);
                                mn = min(mn,ret);
                            }
                        }
                    }
                    ans = max(ans,mn);
                }

            }
        }

        printf("%d\n",ans);
    }    
    
    return 0;    
}
