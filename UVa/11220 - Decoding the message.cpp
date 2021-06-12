#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
    int T,tc,i;
    char ans[1005],s[1005],*delimit;

    tc = 1;
    scanf("%d ",&T);
    while(T--)
    {
        int len,num,cnt,idx;
        printf("Case #%d:\n",tc++);
        while(gets(s))
        {
            if(s[0] == '\0') 
                break;

            num = 1;
            delimit = strtok(s," ");
            while(delimit)
            {
                len = strlen(delimit);
                if(len >= num)
                {
                    printf("%c",delimit[num-1]);
                    num++;
                }
                delimit = strtok(NULL," ");
            }
            putchar('\n');
        }

        if(T)
            putchar('\n');
    }
    return 0;    
}
