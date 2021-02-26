#include <cstdio>
#include <algorithm>
using namespace std;
int n,m;
int i,j;
int A[10000];

int binary(int x)
{
    int l = 0,r = n-1;
    while(l <= r)
    {
        int m = l+(r-l)/2;
        if(x == A[m]) return m;
        else if(A[m] < x) l = m+1;
        else r = m-1;
    }
    return -1;
}

int main()
{   
    while(scanf("%d",&n) == 1)
    {
        int x,y; 
        int mn = 1e9; int d;
        for(i = 0; i < n; i++) scanf("%d",&A[i]);
    
        scanf("%d",&m); sort(A,A+n);
        for(i = 0; i < n; i++)
        {
            int other = m-A[i]; 
            j = binary(other);
            if(j != -1 && j != i)
            {
                d = abs(A[i]-A[j]);
                if(mn > d)
                {
                    mn = d;
                    x = A[i]; y = A[j];
                }
            }
        }
        printf("Peter should buy books whose prices are %d and %d.\n\n",x,y);
    }
    return 0;
}
