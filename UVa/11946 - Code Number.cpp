#include <cstdio>
#include <ctype.h>
using namespace std;
int T,N;
char s[100];

void deleteNewLine(char s[])
{
    int i = 0;
    while(s[i] != '\n') i++;
    s[i] = '\0';
}

int main()
{
    char A[10] = {'O','I','Z','E','A','S','G','T','B','P'};
    scanf("%d ",&T);
    while(T--)
    {
        while(fgets(s,sizeof(s),stdin))
        {
            int i;
            deleteNewLine(s);
            if(s[0] == '\0') break;
            for(i = 0 ; s[i]; i++)
                if(isdigit(s[i])) s[i] = A[s[i]-'0'];
            puts(s);
        }
        if(T) putchar('\n');
    }
    return 0;   
}
