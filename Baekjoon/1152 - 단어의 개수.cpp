#include <cstdio>
using namespace std;

void delete_newline(char s[])
{
    int i;
    i = 0;
    while(s[i] != '\n')
        i++;
    s[i] = '\0';
}

int main()
{
    int i,state,ans;
    char A[1000005];
    fgets(A,sizeof(A),stdin);
    delete_newline(A);

    state = ans = 0;
    for(i = 0; A[i]; i++)
    {
        if(A[i] == ' ' || A[i] == '\t' || A[i] == '\n')
            state = 0;
        else if(!state)
        {
            state = 1;
            ans++;
        }
    }

    printf("%d\n",ans);
    return 0;    
}
