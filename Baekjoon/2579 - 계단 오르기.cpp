#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
    int i,N;
    scanf("%d",&N);
    int A[305],dp[305] = {};

    for(i = 1; i <= N; i++)
        scanf("%d",&A[i]);

    dp[1] = A[1];
    dp[2] = A[1]+A[2];

    for(i = 3; i <= N; i++)
    {
        dp[i] = A[i]+A[i-1]+dp[i-3];
        dp[i] = max(dp[i],A[i]+dp[i-2]);
    }

    printf("%d\n",dp[N]);
    return 0;    
}
