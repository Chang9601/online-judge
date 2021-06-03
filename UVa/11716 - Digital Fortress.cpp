#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

void delete_newline(char s[])
{
    int i = 0;
    while(s[i] != '\n')
        i++;
    s[i] = '\0';
}

int main()
{
    int T;

    scanf("%d ",&T);
    while(T--)
    {
        bool ok;
        int i,j,len,sq;
        char s[10005];
        char A[105][105];

        fgets(s,sizeof(s),stdin);
        delete_newline(s);
        ok = true;
        len = strlen(s);
        sq = sqrt(len);

        if(sq*sq != len)
            ok = false;

        if(ok)
        {
            for(i = 0; i < sq; i++)
                for(j = 0; j < sq; j++)
                    A[i][j] = s[i*sq+j];
        }

        if(ok)
        {
            for(i = 0; i < sq; i++)
                for(j = 0; j < sq; j++)
                    printf("%c",A[j][i]);
        }
        else
            printf("INVALID");
        
        putchar('\n');
    }
    return 0;    
}
