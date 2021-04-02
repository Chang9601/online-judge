#include <cstdio>
#include <algorithm>
using namespace std;
#define INF 1000000000
int n,x;
int A[1000005];
int dp[1000005];

int main()
{
    scanf("%d %d",&n,&x); int i,j;
    for(i = 0; i < n; i++) scanf("%d",&A[i]);
    for(i = 0; i <= x; i++) dp[i] = INF;
    dp[0] = 0;

    for(i = 1; i <= x; i++)
    {
        for(j = 0; j < n; j++)
            if(i-A[j] >= 0) 
                dp[i] = min(dp[i],dp[i-A[j]]+1);
    }

    printf("%d",(dp[x] == INF) ? -1 : dp[x]);
    return 0;   
}
