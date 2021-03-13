#include <cstdio>
#include <cstring>
using namespace std;
int G;
char A[105];

void reverse(int s,int e)
{
    int i,j;
    for(i = s,j = e; i < j; i++,j--)
    {
        char t = A[i];
        A[i] = A[j];
        A[j] = t;
    }
}

int main()
{  
    while(scanf("%d",&G) == 1)
    {
        if(!G) break;
        scanf("%s",A);

        int i,j,len;
        len = strlen(A)/G;

        for(i = 0; A[i]; i += len)
            reverse(i,i+len-1);
        printf("%s\n",A);
    }
    return 0;   
}
