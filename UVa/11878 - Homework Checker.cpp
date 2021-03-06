#include <cstdio>
#include <cstring>
#include <cmath>
#include <ctype.h>
using namespace std;
char s[20],t[20];
char *A[4];

int main()
{
    int ans = 0;
    while(scanf("%s",s) == 1)
    {
        strcpy(t,s);
        int idx = 0; int i;
        char *d = strtok(s,"+-=");

        while(d)
        {
            A[idx++] = d;
            d = strtok(NULL,"+-=");
        }

        if(!strcmp(A[2],"?")) continue;
        int a = atoi(A[0]); int b = atoi(A[1]); int c = atoi(A[2]);

        for(i = 0; isdigit(t[i]); ++i);

        switch(t[i])
        {
            case '+':
                a += b;
                break;
            case '-':
                a -= b;
                break;
        }

        ans += (a == c) ? 1 : 0;
    }
    printf("%d\n",ans);
    return 0;   
}
