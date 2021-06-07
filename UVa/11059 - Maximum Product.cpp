#include <cstdio>
#include <algorithm>
using namespace std;


int main()
{
    int N,idx;
    idx = 1; 
    while(scanf("%d",&N) == 1)
    {
        long long A[20],p,ans;
        int i,j,k;
        ans = -1;

        for(i = 0; i < N; i++)
            scanf("%lld",&A[i]);

        for(i = 0; i < N; i++)
        {
            for(j = i; j < N; j++)
            {
                p = 1;
                for(k = i; k <= j; k++)
                {
                    p *= A[k];
                    ans = max(ans,p);
                }
            }        
        }

        printf("Case #%d: The maximum product is %lld.\n\n",idx++,(ans < 0) ? 0 : ans);
    }

    return 0;    
}
