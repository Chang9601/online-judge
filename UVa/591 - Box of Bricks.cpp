#include <cstdio>
using namespace std;
int n,h;
int A[55];

int main()
{  
    int idx = 1;    
    while(scanf("%d",&n) == 1 && n)
    {
        int i,avg,ans;
        avg = ans = 0;
        for(i = 0; i < n; i++)
        {
            scanf("%d",&A[i]);
            avg += A[i];
        }
        avg /= n;

        for(i = 0; i < n; i++)
            if(A[i] > avg) ans += A[i]-avg;
        printf("Set #%d\n",idx++);
        printf("The minimum number of moves is %d.\n\n",ans);
    }
    return 0;   
}
