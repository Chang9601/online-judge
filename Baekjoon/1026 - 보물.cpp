#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

int cmp(const int *a,const int *b)
{
    if(*a < *b)
        return -1;
    else if(*a > *b)
        return 1;
    else
        return 0;
}

void reverse(int A[],int N)
{
    int i,j,tmp;
    
    for(i = 0,j = N-1; i < j; i++,j--)
    {
        tmp = A[i];
        A[i] = A[j];
        A[j] = tmp;
    }
}
int main()
{
    int i,N,ans,idx,mx;
    int A[55],B[55];
    
    ans = 0;
    scanf("%d",&N);
    for(i = 0; i < N; i++)
        scanf("%d",&A[i]);
    for(i = 0; i < N; i++)
        scanf("%d",&B[i]);
        
    qsort(A,N,sizeof(A[0]),((int(*)(const void*,const void*))cmp));
    qsort(B,N,sizeof(B[0]),((int(*)(const void*,const void*))cmp));
    reverse(B,N);
    
    for(i = 0; i < N; i++)    
        ans += A[i]*B[i];
        
    printf("%d\n",ans);
    return 0;
}
