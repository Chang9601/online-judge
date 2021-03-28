#include <cstdio>
using namespace std;
int N;
int A[10005];

int main()
{
    while(scanf("%d",&N) == 1)
    {
        if(!N) break;
        int i,ans = 0; bool ok1,ok2;

        for(i = 0; i < N; i++) scanf("%d",&A[i]);
        for(i = 0; i < N; i++)
        {
            ok1 = ok2 = false;

            if(A[i] > A[(i+1)%N] && A[i] > A[(i+N-1)%N]) ok1 = true;
            if(A[i] < A[(i+1)%N] && A[i] < A[(i+N-1)%N]) ok2 = true;

            if(ok1 || ok2) ans++;
        }
        printf("%d\n",ans);
    }
    return 0;   
}
