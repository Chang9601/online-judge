#include <iostream>
using namespace std;
#define MOD 10007

int main() {
    int i,n;
    int dp[1005];
   
    dp[1] = 1;
    dp[2] = 2;
    
    scanf("%d",&n);
    for(i = 3; i <= n; i++)
    {
        dp[i] = dp[i-1]+dp[i-2];
        dp[i] %= MOD;
    } 
    
    printf("%d\n",dp[n]);
    return 0;
}
