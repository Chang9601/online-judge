#include <cstdio>
using namespace std;
int n,a,b;

int main()
{
    while(scanf("%d",&n) == 1)
    {
        if(!n) break;
        int cnt = 1,t; a = b = 0;

        while(n)
        {
            t = n & (-n);
            if(cnt & 1) a += t;
            else b += t;
            cnt++;
            n &= (n-1);
        }
        printf("%d %d\n",a,b);
    }
    return 0;   
}
