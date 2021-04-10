#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
char s[105];
void deleteNewline(char str[])
{
    int i = 0;
    while(str[i] != '\n') i++;
    str[i] = '\0';
}

int main()
{
    fgets(s,sizeof(s),stdin);
    while(fgets(s,sizeof(s),stdin))
    {
        deleteNewline(s);
        if(s[0] == '-')
            break;
        int i,j,num;
        i = strlen(s)-2; j = 0; 
        num = 0;
        for(; i >= 0 && s[i] == 'o' || s[i] == ' ' || s[i] == '.'; i--)
        {
            if(s[i] == '.')
                continue;
            if(s[i] == 'o') 
                num += pow(2,j);
            j++;
        }
        putchar((char)num);
    }
    return 0;      
}
