#include <cstdio>
#include <cstring>
#include <ctype.h>
using namespace std;
char s[100];
void reverse(char s[])
{
    int i,j;
    for(i = 0,j = strlen(s)-1; i < j; i++,j--)
    {
        char t = s[i];
        s[i] = s[j];
        s[j] = t;
    }
}

int main()
{
    int ASCII[256]; int i,n,len; char c;
    for(i = 0; i < 128; i++) ASCII[i] = i;

    while(gets(s))
    { 
        reverse(s);
        if(isdigit(s[0]))
        {
            i = 0; len = strlen(s);
            while(i < len && (c = s[i++]))
            {
                n = c-'0';
                if(c >= '3' && c <= '9') n = 10*n+(s[i++]-'0');
                else
                {
                    n = 10*n+(s[i++]-'0');
                    n = 10*n+(s[i++]-'0');
                }
                printf("%c",(char)n);
            }
        }
        else
        {
            for(i = 0; s[i]; i++)
            {
                n = s[i];
                do
                {
                    printf("%d",n%10);
                    n /= 10;
                }while(n);
                
            }
        }
        puts("");
    }
    return 0;   
}
