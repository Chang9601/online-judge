#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
int n;
struct Customer{
    int x,s;
};
Customer A[400005];

int cmp(const Customer *a,const Customer *b)
{
    if((*a).x < (*b).x) return -1;
    else if((*a).x > (*b).x) return 1;
    return 0;
}

int main()
{
    scanf("%d",&n); int i,a,b,cnt = 0,ans = 0;
    for(i = 0; i < 2*n; i += 2)
    {
        scanf("%d %d",&a,&b);
        A[i].x = a; A[i].s = 0;
        A[i+1].x = b; A[i+1].s = 1;
    }

    qsort(A,2*n,sizeof(Customer),(int(*)(const void*,const void*))cmp);
    for(i = 0; i < 2*n; i++)
    {
        if(A[i].s == 0) cnt++;
        else cnt--;
        ans = max(ans,cnt);
    }
    printf("%d\n",ans);
    return 0;   
}
