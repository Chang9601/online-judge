#include <cstdio>
using namespace std;

int main()
{
    int i,j,t,n,p,ret;
    int A[20];
    bool ans;

    scanf("%d",&t);
    while(t--)
    {
        ans = false;
        scanf("%d",&n);
        scanf("%d",&p);

        for(i = 0; i < p; i++)
            scanf("%d",&A[i]);
        
        for(i = 0; i < (1 << p); i++)
        {
            ret = 0;
            for(j = 0; j < p; j++)
                if(i & (1 << j))
                    ret += A[j];
            if(ret == n)
                ans = true;
        }

        printf("%s\n",ans ? "YES" : "NO");
    }

    return 0;    
}
