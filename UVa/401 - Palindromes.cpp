#include <cstdio>
#include <cstring>
using namespace std;
const char *c = "ABCDEFGHIJKLMNOPQRSTUVWXYZ123456789";
const char *r = "A   3  HIL JM O   2TUVWXY51SE Z  8 ";

bool is_palindrome(char s[])
{
    int i,j;

    j = strlen(s)-1;
    for(i = 0; i < j; i++,j--)
        if(s[i] != s[j])
            return false;
    return true;
}

bool is_mirror(char s[])
{
    int i,j,idx;
    char t[25];

    idx = 0;
    for(i = 0; s[i]; i++)
    {
        for(j = 0; c[j]; j++)
            if(s[i] == c[j] && r[j] != ' ')
                t[idx++] = r[j];
    }

    t[idx] = '\0';
    j = strlen(s)-1;
    if(idx-1 == j)
    {
        for(i = 0; i < j; i++,j--)
            if(s[i] != t[j])
                return false;
        return true;
    }
    else
        return false;
}

int main()
{  
    char s[25];

    while(scanf("%s",s) == 1)
    {
        bool is_p,is_m;
        is_p = is_m = false;

        is_p = is_palindrome(s);
        is_m = is_mirror(s);

        if(is_p && is_m)
            printf("%s -- is a mirrored palindrome.",s);
        else if(is_p && !is_m)
            printf("%s -- is a regular palindrome.",s);
        else if(!is_p && is_m)
            printf("%s -- is a mirrored string.",s);
        else
            printf("%s -- is not a palindrome.",s);
        putchar('\n');
        putchar('\n');
    }

    return 0;    
}
