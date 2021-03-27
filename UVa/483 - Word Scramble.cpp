#include <cstdio>
#include <cstring>
using namespace std;
char s[1005];
char buf[500];

void reverse(char buf[])
{
    int i,j; char c;

    for(i = 0,j = strlen(buf)-1; i < j; i++,j--)
    {
        c = buf[i];
        buf[i] = buf[j];
        buf[j] = c;
    }
}

int main()
{
    int i,j,c;
    while(fgets(s,sizeof(s),stdin))
    {
        i = j = 0;
        while((c = s[i++]))
        {
            if(c == ' ' || c == '\n')
            {
                buf[j] = '\0';
                reverse(buf);
                printf("%s",buf);
                if(c == ' ') putchar(' ');
                j = 0;
            }
            else buf[j++] = c;
        }
        putchar('\n');
    }

    return 0;   
}
