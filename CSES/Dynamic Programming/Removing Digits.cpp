#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define INF 1000000000
int n;
long long dp[1000005];
char buf[10];

int main()
{
    scanf("%d",&n);
    int i,j,len;
    for(i = 0; i <= n; i++) dp[i] = INF;
    dp[0] = 0; 
    for(i = 1; i <= n; i++)
    {
        sprintf(buf,"%d",i);
        len = strlen(buf);
        for(j = 0; j < len; j++)
            dp[i] = min(dp[i],dp[i-(buf[j]-'0')]+1);
    }

    printf("%lld",dp[n]);
    return 0;   
}
