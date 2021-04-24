#include <cstdio>
#include <algorithm>
using namespace std;
int n,m;
long long A[1005];
long long q;

int main()
{   
    int idx = 1;
    while(scanf("%d",&n) == 1 && n)
    {
        int i,j; long long ans,x,d,mn;
        for(i = 0; i < n; i++)
            scanf("%lld",&A[i]);

        scanf("%d",&m);
        printf("Case %d:\n",idx++);
        while(m--)
        {
            mn = 1e18;
            scanf("%lld",&q);
            for(i = 0; i < n; i++)
            {
                for(j = i+1; j < n; j++)
                {
                    x = A[i]+A[j];
                    d = abs(x-q);
                    if(mn > d)
                    {
                        ans = x;
                        mn = d;
                    }
                }
            }

            printf("Closest sum to %lld is %lld.\n",q,ans);
        }

    }    
    return 0;    
}
