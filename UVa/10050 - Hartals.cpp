#include <cstdio>
#include <cstring>
using namespace std;
int T,N,P;
bool ok[3700];
int A[3700];

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d %d",&N,&P); int i,j,x,ans = 0;
        memset(ok,false,sizeof(ok));

        for(i = 0; i < P; i++)
            scanf("%d",&A[i]);
        for(i = 0; i < P; i++)
            for(j = A[i]; j <= N; j += A[i])
                ok[j] = true;
        for(i = 1; i <= N; i++)
            if(i%7 != 6 && i%7 != 0 && ok[i]) ans++;
        printf("%d\n",ans);
    }
    return 0;   
}

