#include <cstdio>
using namespace std;
int t,n;
int dp[12];

int main()
{   
    int i;
    dp[0] = dp[1] = 1;
    for(i = 2; i < 12; i++)
    {
        dp[i] += dp[i-1];
        if(i-2 >= 0) dp[i] += dp[i-2];
        if(i-3 >= 0) dp[i] += dp[i-3];
    }

    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);;
        printf("%d\n",dp[n]);
    }

    return 0;
}
