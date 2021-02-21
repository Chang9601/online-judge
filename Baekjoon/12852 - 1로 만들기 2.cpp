#include <cstdio>
using namespace std;
int N;
int dp[1000005];
int p[1000005];

int main()
{   
    
    int i; scanf("%d",&N);
    p[1] = 1;

    for(i = 2; i <= N; i++)
    {
        dp[i] = dp[i-1]+1;
        p[i] = i-1;
        if(i%2 == 0)
        {
            if(dp[i] > dp[i/2]+1)
            {
                dp[i] = dp[i/2]+1;
                p[i] = i/2;
            }
        }
        if(i%3 == 0) 
        {
            if(dp[i] > dp[i/3]+1)
            {
                dp[i] = dp[i/3]+1;
                p[i] = i/3;
            }
        }
    }

    printf("%d\n",dp[N]);
    int t = N;
    while(t != 1)
    {
        printf("%d ",t);
        t = p[t];
    }

    printf("1");
    return 0;
}
