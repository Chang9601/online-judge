#include <iostream>
using namespace std;

int main() {
    int T,n,i,j;
    int dp[15] = {};
    
    dp[1] = dp[2] = dp[3] = 1;
    for(i = 2; i <= 10 ; i++)  
        for(j = 1; j <= 3; j++)
            if(i-j >= 0)
                dp[i] += dp[i-j];
                
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        printf("%d\n",dp[n]);
    }
    return 0;
}
