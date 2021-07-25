#include <cstdio>
using namespace std;

void clear_newline(char str[])
{
    int i;
  
    i = 0;
    while(str[i] != '\n')
        i++;
    str[i] = '\0';
}

int main()
{
    int T;
    int i,j,cnt;
    char s[105];

    char keys[] = "abcdefghijklmnopqrstuvwxyz ";
    char values[] = "123123123123123123412312341";
    
    scanf("%d",&T);
    getchar();
    cnt = 1;
    while(T--)
    {
        int ans = 0;
        fgets(s,sizeof(s),stdin);
        clear_newline(s);

        for(i = 0; s[i]; i++)
        {
            for(j = 0; keys[j]; j++)
                if(s[i] == keys[j])
                    ans += values[j]-'0';
        }

        printf("Case #%d: %d\n",cnt++,ans);
    }
    return 0;    
}
