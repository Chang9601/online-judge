#include <cstdio>
#include <cmath>
using namespace std;
int n;
int A[3005];

int main()
{
    while(scanf("%d",&n) == 1)
    {
        int i,last,d; bool ok = true;
        bool has[3005] = {};
        for(i = 0; i < n; i++) scanf("%d",&A[i]);
        for(i = 0; i < n-1; i++) has[abs(A[i]-A[i+1])] = true;
        for(i = 1; i < n; i++)
            if(!has[i]) ok = false;
        
        printf("%s\n",ok ? "Jolly" : "Not jolly");
    }
    return 0;   
}
