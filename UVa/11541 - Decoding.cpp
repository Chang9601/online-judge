#include <cstdio>
using namespace std;

int main()
{
    int T,i,c,idx,cnt,num;
    char s[205],ans[205];

    cnt = 1;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%s",s);
        i = idx = 0;

        while((c = s[i++]))
        {
            if(c >= 'A' && c <= 'Z')
            {
                num = 0;
                while(s[i] && s[i] >= '0' && s[i] <= '9')
                {
                    num = num*10+(s[i]-'0');
                    i++;
                }

                while(num--)
                    ans[idx++] = c;
            }
        }
        ans[idx] = '\0';
        printf("Case %d: %s\n",cnt++,ans);
    }

    return 0;    
}
