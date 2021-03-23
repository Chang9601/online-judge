#include <cstdio>
using namespace std;
int S;
int A[13],B[13];
int sum;

int main()
{
    int idx = 1;
    while(scanf("%d",&S) == 1)
    {
        if(S < 0) break;
        sum = S; int i;
        for(i = 0; i < 12; i++) scanf("%d",&A[i]);
        for(i = 0; i < 12; i++) scanf("%d",&B[i]);

        printf("Case %d:\n",idx++);
        for(i = 0; i < 12; i++)
        {
            if(sum >= B[i])
            {
                puts("No problem! :D");
                sum -= B[i];
            }
            else puts("No problem. :(");
            sum += A[i];
        }
    }
    return 0;   
}

