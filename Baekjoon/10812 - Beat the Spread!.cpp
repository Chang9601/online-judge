#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    long long s,d,x,y;

    scanf("%d",&n);
    while(n--)
    {
        bool flag;

        flag = true;
        scanf("%lld %lld",&s,&d);
        
        if(((s+d)%2) != 0)
            flag = false;
        else
        {
            x = (s+d)/2;
            y = s-x;

            if(y < 0)
                flag = false;
        }

        if(flag)
        {
            if(x < y)
                swap(x,y);
            printf("%lld %lld\n",x,y);
        }
        else
            printf("impossible\n");
        
    }
    return 0;    
}
