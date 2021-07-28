#include <cstdio>
#include <ctype.h>
#include <utility>
using namespace std;

void clear_newline(char str[])
{
    int i;
    i = 0;
    
    while(str[i] != '\n')
        i++;
    str[i] = '\0';
}

int get_single_digit(int n)
{
    int t;
    while(1)
    {
        if(n >= 0 && n <= 9)
            break;

        t = 0;
        do
        {
            t += n%10;
            n /= 10;
        }while(n);
        n = t;
    }

    return n;
}

int main()
{
    char s1[50],s2[50];
    int i,a,b;
    double c;

    while(fgets(s1,sizeof(s1),stdin))
    {
        clear_newline(s1);
        if(s1[0] == '\0')
            break;

        fgets(s2,sizeof(s2),stdin);
        clear_newline(s2);

        a = b = 0;

        for(i = 0; s1[i]; i++)
            if(isalpha(s1[i]))
                a += (tolower(s1[i])-'a')+1;
            
        for(i = 0; s2[i]; i++)
            if(isalpha(s2[i]))
                b += (tolower(s2[i])-'a')+1;

        a = get_single_digit(a);
        b = get_single_digit(b);

        if(a > b)
            swap(a,b);

        c = 1.0*a/b;
        c *= 100;
        printf("%.2lf %%\n",c);
    }
    return 0;    
}
