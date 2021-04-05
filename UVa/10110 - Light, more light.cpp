#include <cstdio>
#include <cmath>
using namespace std;
unsigned int n;

int main()
{
    while(scanf("%u",&n) == 1)
    {
        if(!n) break;
        int x = sqrt(n);
        if(x*x == n) puts("yes");
        else puts("no");
    }    
    return 0;   
}
