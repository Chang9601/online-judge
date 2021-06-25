#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{  
    int T,N;
    long long P[100005],Q[100005];
    long long sum,mn;
    int i,cnt;

    cnt = 1;
    scanf("%d",&T);
    while(T--)
    {
        sum = 0;
        scanf("%d",&N);

        for(i = 0; i < N; i++)
            scanf("%lld",&P[i]);
        for(i = 0; i < N; i++)
            scanf("%lld",&Q[i]);

        for(i = 0; i < N; i++)
        {
            sum += P[i]-Q[i];
            mn = min(mn,sum);
        }

        i = 0;
        while(i < N && mn < 0)
        {
            mn -= P[i]-Q[i];
            i++;
        }

        printf("Case %d: ",cnt++);
        if(i == N || sum < 0)
            printf("Not possible\n");
        else 
            printf("Possible from station %d\n",i+1);
    }

    return 0;    
}
