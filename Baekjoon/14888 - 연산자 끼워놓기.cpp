#include <cstdio>
#include <cmath>
#define INF 1000000000
using namespace std;
int N;
int A[105];
int mx,mn;

void go(int p,int m,int t,int d,int sum,int cnt)
{
    if(!p && !m && !t && !d)
    {
        mx = max(mx,sum);
        mn = min(mn,sum);
    }

    if(p > 0) go(p-1,m,t,d,sum+A[cnt],cnt+1);
    if(m > 0) go(p,m-1,t,d,sum-A[cnt],cnt+1);
    if(t > 0) go(p,m,t-1,d,sum*A[cnt],cnt+1);
    if(d > 0) go(p,m,t,d-1,sum/A[cnt],cnt+1);
    
}

int main()
{   
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int i; scanf("%d",&N); int a,b,c,d;
    for(i = 0; i < N; i++) scanf("%d",&A[i]);
    scanf("%d %d %d %d",&a,&b,&c,&d); 
    mx = -INF; mn = INF;
    go(a,b,c,d,A[0],1);
    printf("%d\n%d\n",mx,mn);

    return 0;
}
