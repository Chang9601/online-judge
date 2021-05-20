#include <cstdio>
#include <algorithm>
using namespace std;
#define INF 1000000000
char grid[55][55];

int main()
{
    int T,R,C;
    int idx = 1;
    scanf("%d",&T);
    while(T--)
    {
        int i,j,k;
        scanf("%d %d",&R,&C);
        for(i = 0; i < R; i++)
            scanf("%s",grid[i]);
        int ans,mn,sum;
        bool ok = true;
        ans = INF;

        for(i = 0; i < C; i++)
        {
            sum = 0;
            for(j = 0; j < R; j++)
            {
                mn = INF;
                for(k = 0; k < C; k++)
                {
                    if(grid[j][k] == '0')
                        mn = min(mn,abs(i-k));
                }
                if(mn == INF)
                    ok = false;
                else
                    sum += mn;
            }
            ans = min(ans,sum);
        }
        printf("Case %d: %d\n",idx++,(ok == true) ? ans : -1);
    }
    return 0;    
}
