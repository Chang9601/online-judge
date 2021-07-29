#include <cstdio>
#include <ctype.h>
#include <cstring>
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
    char s[10005],buf[105],ans[105];
    int i,idx,mx,size;
    char c;

    mx = -1;
    while(fgets(s,sizeof(s),stdin))
    {
        clear_newline(s);
        if(!strcmp(s,"E-N-D"))
            break;

        i = 0;
        while((c = s[i++]))
        {

            if(isalpha(c) || c == '-')
            {
                idx = 0;
                buf[idx++] = c;
                while(s[i] && (isalpha(s[i]) || s[i] == '-'))
                    buf[idx++] = s[i++];
                buf[idx] = '\0';

                if(idx > 0)
                {
                    if(idx > mx)
                    {
                        mx = idx;
                        strcpy(ans,buf);
                    }
                }
            }
        }
    }

    for(i = 0; ans[i]; i++)
        ans[i] = tolower(ans[i]);
    puts(ans);
    return 0;    
}
