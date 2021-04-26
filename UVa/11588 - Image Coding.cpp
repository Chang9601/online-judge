#include <cstdio>
#include <algorithm>
using namespace std;
int X,R,C,M,N;
char grid[30][30];
int main()
{
    int idx = 1;
    scanf("%d",&X);
    while(X--)
    {
        int i,j;
        int ASCII[128] = {};
        int ans = 0,mx = -1,cnt;
        scanf("%d %d %d %d",&R,&C,&M,&N);
        cnt = R*C;
        for(i = 0; i < R; i++)
            scanf("%s",grid[i]);
        for(i = 0; i < R; i++)
        {
            for(j = 0; j < C; j++)
            {
                ASCII[grid[i][j]-'A']++;
                mx = max(mx,ASCII[grid[i][j]-'A']);
            }
        }
        for(i = 0; i < 128; i++)
            if(mx == ASCII[i])
            {
                ans += mx*M;
                cnt -= mx;
            }

        ans += cnt*N;
        printf("Case %d: %d\n",idx++,ans);
    }  
    return 0;    
}
