#include <iostream>
using namespace std;

int main() {
    int i,s,e;
    int N,M;
    int A[100005],dp[100005];
   
    dp[0] = 0;
    scanf("%d %d",&N,&M);
    for(i = 1; i <= N; i++)
        scanf("%d",&A[i]);
    
    dp[1] = A[1];
    for(i = 2; i <= N; i++)
        dp[i] = A[i]+dp[i-1];
    while(M--)
    {
        scanf("%d %d",&s,&e);
        printf("%d\n",dp[e]-dp[s-1]);
    }
    return 0;
}
