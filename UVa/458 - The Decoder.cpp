#include <cstdio>
using namespace std;
char s[1005];

void deleteNewLine(char s[])
{
    int i;
    while(s[i] != '\n') i++;
    s[i] = '\0';
}

int main()
{
    int i;
    while(fgets(s,sizeof(s),stdin))
    {
        deleteNewLine(s);
        for(i = 0; s[i]; i++) putchar(s[i]-7);
        putchar('\n');
    }

    return 0;   
}
