#include <cstdio>
#include <cstring>
#include <ctype.h>
using namespace std;

bool is_punctation(char c)
{
    return c == '.' || c == ',' || c == '!' || c == '?' || c == ' ';
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
    int i,j;
    char s[1005];
    bool flag;

    while(fgets(s,sizeof(s),stdin))
    {
        clear_newline(s);
        if(!strcmp(s,"DONE"))
            break;
        flag = true;
        for(i = 0; s[i]; i++)
            s[i] = tolower(s[i]);

        i = 0;
        j = strlen(s)-1;

        while(i < j)
        {
            while(i < j && is_punctation(s[i]))
                i++;
            while(j > i && is_punctation(s[j]))
                j--;
            
            if(i < j)
            {
                if(s[i] != s[j])
                {
                    flag = false;
                    break;
                }
                i++;
                j--;
            }
        }

        printf("%s\n",flag ? "You won't be eaten!" : "Uh oh..");

    }
    return 0;    
}
