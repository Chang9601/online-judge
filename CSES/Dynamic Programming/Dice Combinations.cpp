#include <cstdio>
#include <cstring>
using namespace std;
#define SIZE 1000005
const long long m = 1e9+7;
int n;
long long dp[SIZE];

int main()
{
    int i,j;
    scanf("%d",&n);
    memset(dp,0,n);
    dp[0] = 1;
    
    for(i = 1; i <= n; i++)
        for(j = 1; j <= 6; j++)
            if(i-j >= 0)
            {
                dp[i] += dp[i-j];
                dp[i] %= m;
            }
    printf("%lld\n",dp[n]);

    return 0;   
}
