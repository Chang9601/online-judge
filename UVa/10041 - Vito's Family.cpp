#include <cstdio>
#include <algorithm>
using namespace std;
int t,r;
int A[501];
int cmp(const int *a,const int *b)
{
    if(*a < *b)
        return -1;
    else if(*a > *b)
        return 1;
    else
        return 0;    
}

int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&r); int i,j; long long ans = 0;
        for(i = 0; i < r; i++) scanf("%d",&A[i]);
        qsort(A,r,sizeof(A[0]),(int(*)(const void*,const void*))cmp);

        for(i = 0; i < r; i++)
            ans += abs(A[r/2]-A[i]);
        printf("%lld\n",ans);
    }
    return 0;    
}
