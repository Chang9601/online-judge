#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int L,C;
char A[15];
bool chosen[15];
const char *vowels = "aeiou";

bool is_vowel(char c)
{
    int i;
    for(i = 0; vowels[i]; i++)
        if(c == vowels[i]) return true;
    return false;
}

void go(int cnt,int idx,int v,int c,char str[])
{
    if(cnt == L)
    {
        if(v >= 1 && c >= 2)
        {
            str[cnt] = '\0';
            printf("%s\n",str);
        }
        return;
    }

    for(int i = idx; i < C; i++)
    {
        if(chosen[i]) continue;
        chosen[i] = true;
        str[cnt] = A[i];
        if(is_vowel(A[i])) go(cnt+1,i,v+1,c,str);
        else go(cnt+1,i,v,c+1,str);
        chosen[i] = false;
    }
}

int main()
{   
    scanf("%d %d ",&L,&C); int i = 0,j; char str[50]; //string s;
    fgets(str,sizeof(str),stdin); for(i = 0,j = 0; i < C; i++,j += 2) A[i] = str[j];
   // for(i = 0; i < C; i++) printf("%c ",A[i]);
    sort(A,A+C); memset(str,'\0',sizeof(str));
    go(0,0,0,0,str);
    return 0;
}
