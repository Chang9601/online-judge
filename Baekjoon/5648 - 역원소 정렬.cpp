#include <cstdio>
#include <cstdlib>
using namespace std;

long long reverse_integer(long long num)
{
    long long n = 0;
    do
    {
        n = 10*n+num%10;
        num /= 10;
    }while(num);
    
    return n;
}

int cmp(const long *a,const long *b)
{
    if(*a < *b)
        return -1;
    else if(*a > *b)
        return 1;
    else
        return 0;
}

int main() {
    int i,n;
    long long A[1000005];
    scanf("%d",&n);
    
    for(i = 0; i < n; i++)
        scanf("%lld",&A[i]);
    for(i = 0; i < n; i++)
        A[i] = reverse_integer(A[i]);
    
    qsort(A,n,sizeof(A[0]),(int(*)(const void*,const void*))cmp); 
    for(i = 0; i < n; i++)
        printf("%lld\n",A[i]);
        
    return 0;
}
