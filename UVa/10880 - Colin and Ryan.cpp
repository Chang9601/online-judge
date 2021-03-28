#include <cstdio>
#include <cstdlib>
long long C,R,Q;
long long A[100005];
int N,idx;

int cmp(const long *a,const long *b)
{
    if(*a < *b) return -1;
    else if(*a > *b) return 1;
    else return 0;
}

void factors(long long x)
{
    long long i,j;
    for(i = 1; i*i <= x; i++)
    {
        if(x%i == 0)
        {
            j = x/i;
            A[idx++] = i;
            if(i != j) A[idx++] = j;
        }
    }
}

int main()
{
    scanf("%d",&N); int cnt = 1;
    while(N--)
    {
        scanf("%lld %lld",&C,&R); int i;
        Q = C-R; idx = 0;
        factors(Q); qsort(A,idx,sizeof(A[0]),(int(*)(const void*,const void*))cmp);

        printf("Case #%d:",cnt++);
       if(R == C) printf(" 0");
       else
       {
           for(i = 0; i < idx; i++)
                if(A[i] > R) printf(" %d",A[i]);
       }
       putchar('\n');
    }    
    return 0;   
}
