#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
int F[105],R[105];
double A[10005];
int f,r;

int cmp(const double *a,const double *b)
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
    while(scanf("%d",&f) == 1)
    {
        if(!f)
            break;
        scanf("%d",&r);
        int i,j,cnt = 0;
        double ans;
        for(i = 0; i < f; i++)
            scanf("%d",&F[i]);
        for(i = 0; i < r; i++)
            scanf("%d",&R[i]);

        for(i = 0; i < r; i++)
            for(j = 0; j < f; j++)
                A[cnt++] = (double)R[i]/F[j];
        qsort(A,cnt,sizeof(A[0]),(int(*)(const void*,const void*))cmp);
        ans = -100.0;
        for(i = 0; i < cnt-1; i++)
            ans = max(ans,A[i+1]/A[i]);
        printf("%.2lf\n",ans);
    }
    return 0;    
}
