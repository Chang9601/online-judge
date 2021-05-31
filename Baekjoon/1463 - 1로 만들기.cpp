#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
    int i,N;
    scanf("%d",&N);
    int dp[1000005];
    dp[1] = 0;
    for(i = 2; i <= N; i++)
    {
        dp[i] = dp[i-1]+1;
        if(i%3 == 0)
            dp[i] = min(dp[i],dp[i/3]+1);
        if(i%2 == 0)
            dp[i] = min(dp[i],dp[i/2]+1);
    }

    printf("%d\n",dp[N]);
    return 0;    
}
