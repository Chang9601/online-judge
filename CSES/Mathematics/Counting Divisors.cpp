#include <cstdio>
using namespace std;
int n,x;

int go()
{
    int cnt = 0; int i,j;

    for(i = 1; i*i <= x; i++)
    {
        if(x%i == 0)
        {
            j = x/i;
            cnt++;
            if(i != j) cnt++;
        }
    }
    return cnt;
}

int main()
{
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d",&x);
        printf("%d\n",go());
    }
    return 0;   
}
