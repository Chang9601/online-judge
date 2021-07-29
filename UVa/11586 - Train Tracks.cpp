#include <cstdio>
#include <cstring>
using namespace std;

void clear_input_buffer()
{
    while(getchar() != '\n')
        ;
}

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
    int T,i,size,m,f;
    char s[205];

    scanf("%d",&T);
    clear_input_buffer();
    while(T--)
    {
        fgets(s,sizeof(s),stdin);
        clear_newline(s);
    
        m = f = 0;
        size = strlen(s);
        for(i = 0; i < size; i += 3)
        {
            m += (s[i] == 'M') ? 1 : 0;
            m += (s[i+1] == 'M') ? 1 : 0;

            f += (s[i] == 'F') ? 1 : 0;            
            f += (s[i+1] == 'F') ? 1 : 0;
        }

        if(m == f && m > 1 && f > 1)
            puts("LOOP");
        else
            puts("NO LOOP");
    }

    return 0;    
}
