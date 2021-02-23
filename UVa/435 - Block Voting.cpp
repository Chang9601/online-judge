#include <cstdio>
#include <cstring>
using namespace std;
int t,p;
int a[20];

int main()
{   
    scanf("%d",&t);
    while(t--)
    {
        int sum = 0; int cnt[20] = {},ans[20] = {}; int idx = 0;

        scanf("%d",&p);
        for(int i = 0; i < p; i++)
        {
            scanf("%d",&a[i]);
            sum += a[i];
        }
        sum /= 2;

        for(int i = 0; i < (1 << p); i++)
        {
            int t = 0; idx = 0; memset(cnt,0,sizeof(cnt));
            for(int j = 0; j < p; j++)
            {
                if(i&(1 << j))
                {
                    t += a[j];
                    cnt[j] = 1;
                   // idx++;
                }
            }
            if(t <= sum)
            {
                for(int j = 0; j < p; j++)
                    if(t+a[j] > sum && !cnt[j])
                        ans[j]++;
            }
        }
        for(int i = 0; i < p; i++)
            printf("party %d has power index %d\n",i+1,ans[i]);
        puts("");
    }    
    return 0;
}
