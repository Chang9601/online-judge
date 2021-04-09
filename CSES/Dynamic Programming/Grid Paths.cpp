#include <cstdio>
using namespace std;
const long long m = (1e9+7);
int n;
char grid[1005][1005];
long long dp[1005][1005];

int main()
{
    int i,j;
    scanf("%d",&n);
    dp[0][0] = 1;

    for(i = 0; i < n; i++) scanf("%s",grid[i]);
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            if(grid[i][j] == '*') continue;

            if(i-1 >= 0) dp[i][j] += dp[i-1][j];
            if(j-1 >= 0) dp[i][j] += dp[i][j-1];
            dp[i][j] %= m;
        }
    }

    printf("%lld",(grid[0][0] == '*') ? 0 : dp[n-1][n-1]);
    return 0;      
}
