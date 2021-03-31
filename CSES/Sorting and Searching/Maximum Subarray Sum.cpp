#include <cstdio>
#include <algorithm>
using namespace std;
long long A[200005];
long long dp[200005];
long long ans;
int n;

int main()
{
    int i; 
    scanf("%d",&n); 
    for(i = 0; i < n; i++) scanf("%lld",&A[i]);
    
    ans = dp[0] = A[0];
    for(i = 1; i < n; i++)
    {
        dp[i] = max(A[i],dp[i-1]+A[i]);
        ans = max(ans,dp[i]);
    }
    printf("%lld",ans);
    return 0;   
}
