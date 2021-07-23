#include <cstdio>
#include <cstring>
using namespace std;

void clear_input_buffer()
{
    while(getchar() != '\n')
        ;
}

void clear_newline(char s[])
{
    int i = 0;
    while(s[i] != '\n')
        i++;
    s[i] = '\0';
}

int main()
{
    int N,i;
    char cmd[10];

    bool vis[11];
    memset(vis,true,sizeof(vis));
    while(scanf("%d",&N) == 1 && N)
    {
        bool flag;
        flag = false;

        clear_input_buffer();
        fgets(cmd,sizeof(cmd),stdin);
        clear_newline(cmd);

        if(!strcmp(cmd,"too high"))
        {
            for(i = N; i <= 10; i++)
                vis[i] = false;
        }
        else if(!strcmp(cmd,"too low"))
        {
            for(i = N; i >= 1; i--)
                vis[i] = false;
        }
        else
        {  
            if(vis[N])
                puts("Stan may be honest");
            else
                puts("Stan is dishonest");
            memset(vis,true,sizeof(vis));
        }
    }

    return 0;    
}
