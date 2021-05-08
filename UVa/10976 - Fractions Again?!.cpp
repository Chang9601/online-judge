#include <cstdio>
#include <algorithm>
using namespace std;
int go(int n,bool ok)
{
    int cnt = 0;
    int m = n*n;
    int i,x,y;
    for(i = 1; i*i <= m; i++)
    {
        if(m%i == 0)
        {
            cnt++;
            x = m/i;
            y = m/x;
            x += n;
            y += n;

            if(!ok)
                continue;
            if(x < y)
                swap(x,y);
            printf("1/%d = 1/%d + 1/%d\n",n,x,y); 
        }
    }
    return cnt;
}

int main()
{
    int k,ans;
    while(scanf("%d",&k) == 1)
    {
        int ans = go(k,false);
        printf("%d\n",ans);
        go(k,true);
    }    
    return 0;    
}
