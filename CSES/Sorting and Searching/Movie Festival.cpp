#include <cstdio>
#include <cstdlib>
using namespace std;
struct Movie{
    int s,e;
};
Movie A[200005];
int n,a,b;

int cmp(const Movie *a,const Movie *b)
{
    if((*a).e < (*b).e) return -1;
    else if((*a).e > (*b).e) return 1;
    else return 0;
}

int main()
{
    scanf("%d",&n); int i,j,last,ans;
    for(i = 0; i < n; i++)
    {
        scanf("%d %d",&a,&b);
        A[i].s = a; A[i].e = b;
    }
    qsort(A,n,sizeof(Movie),(int(*)(const void*,const void*))cmp);
    last = A[0].e; ans = 1;

    for(i = 1; i < n; i++)
    {  
        if(last <= A[i].s)
        {
            last = A[i].e;
            ans++;
        }
    }

    printf("%d\n",ans);
    return 0;   
}
