#include <cstdio>
using namespace std;

int main()
{
    int t,n,k,idx = 1;
    scanf("%d",&t);
    while(t--)
    {
        int i,j,ans = 0; 
        char s[505];
        int ok[30];
        scanf("%d %d %s",&n,&k,s);

        for(i = 0; i < 30; i++)
            ok[i] = -100000;

        for(i = 0; s[i]; i++)
        {
            if(i-ok[s[i]-'A'] <= k)
                ans++;
            ok[s[i]-'A'] = i;
        }
        printf("Case %d: %d\n",idx++,ans);
    }
    return 0;    
}
