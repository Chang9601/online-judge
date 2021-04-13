#include <cstdio>
using namespace std;
char s[1005];
void deleteNewline(char str[])
{
    int i = 0;
    while(str[i] != '\n')
        i++;
    s[i] = '\0';
}

int main()
{
    char QWERTY[] = "1234567890-=qwertyuiop[]\\asdfghjkl;\'zxcvbnm,./";
    char DVOARK[] = "123qjlmfp/[]456.orsuyb;=\\789aehtdck-0zx,inwvg\'";
    char QWERTYU[] = "!@#$%^&*()_+QWERTYUIOP{}|ASDFGHJKL:\"ZXCVBNM<>?";
    char DVOARKU[] = "!@#QJLMFP?{}$%^>ORSUYB:+|&*(AEHTDCK_)ZX<INWVG\"";
    while(fgets(s,sizeof(s),stdin))
    {
        deleteNewline(s);
        int i,j,k; bool ok;
        for(i = 0; s[i]; i++)
        {
            ok = false;
            for(j = 0; QWERTY[j]; j++)
                if(QWERTY[j] == s[i])
                {   
                    putchar(DVOARK[j]);
                    ok = true;
                    break;
                }

            for(j = 0; QWERTYU[j]; j++)
                if(QWERTYU[j] == s[i])
                {
                    putchar(DVOARKU[j]); 
                    ok = true;
                    break;
                }

            if(!ok)
                putchar(s[i]);      
        }
        putchar('\n'); 
    }

    return 0;    
}
