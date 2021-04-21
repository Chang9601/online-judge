#include <cstdio>
using namespace std;
int T,n;

int main()
{  
    scanf("%d",&T);
    while(T--)
    {
        int A[1005];
        int i,j,cnt,ans = 0;
        scanf("%d",&n);
        for(i = 1; i <= n; i++)
            scanf("%d",&A[i]);
        for(i = 2; i <= n; i++)
        {
            cnt = 0;
            for(j = 1; j < i; j++)
            {
                if(A[j] <= A[i])
                    cnt++;
            }
            ans += cnt;
        }
        printf("%d\n",ans);
    }
    return 0;    
}
