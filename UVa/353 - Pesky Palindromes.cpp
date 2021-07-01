#include <cstdio>
#include <cstring>
#include <set>
using namespace std;

bool is_palindrome(char str[],int idx)
{
    str[idx] = '\0';
    int i,j;

    for(i = 0,j = strlen(str)-1; i < j; i++,j--)
        if(str[i] != str[j])
            return false;
    return true;
}

int main()
{  
    char str[100],t[100];
    int i,j,k,size,idx;

    while(scanf("%s",str) == 1)
    {
        set<string> s;
        size = strlen(str);
        for(i = 0; i < size; i++)
        {
            for(j = i; j < size; j++)
            {
                idx = 0;
                for(k = i; k <= j; k++)
                {
                    t[idx++] = str[k];
                    if(is_palindrome(t,idx))
                        s.insert(t);
                }
            }
        }     

        printf("The string \'%s\' contains %d palindromes.\n",str,(int)s.size());
    }

    return 0;    
}
