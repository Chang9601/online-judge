#include <cstdio>
#include <set>
#include <algorithm>
using namespace std;
int n,m;
long long A[200005];
multiset<long long> ms;
multiset<long long>::iterator it;
long long k,x;
int ans;
int main()
{
    scanf("%d %d %lld",&n,&m,&k); int i;
    for(i = 0; i < n; i++) scanf("%lld",&A[i]);
    for(i = 0; i < m; i++)
    {
        scanf("%lld",&x);
        ms.insert(x);
    }

    sort(A,A+n);
    for(i = 0; i < n; i++)
    {
        it = ms.lower_bound(A[i]-k);  
        if(it == ms.end()) continue;

        if(*it <= A[i]+k)
        {
            ms.erase(it);
            ans++;
        }
    }
    printf("%d\n",ans);
    return 0;   
}
