#include <cstdio>
#include <cstring>
using namespace std;
long long n1,n2;
int digit,ans;
void go(char s1[],char s2[],int i,int j)
{
    if(s1) digit += (s1[i]-'0'); 
    if(s2) digit += (s2[j]-'0');
    digit /= 10;
    if(digit) ans++;
}

int main()
{
    while(scanf("%lld %lld",&n1,&n2) == 2)
    {
        if(!n1 && !n2) break;
        char s1[15],s2[15];
        digit = ans = 0; int i,j;
        sprintf(s1,"%lld",n1); sprintf(s2,"%lld",n2);

        for(i = strlen(s1)-1,j = strlen(s2)-1; i >= 0 && j >= 0; i--,j--)
            go(s1,s2,i,j);
        
        while(i >= 0)
        {
            go(s1,NULL,i,-1);
            i--;
        }  

        while(j >= 0)
        {
            go(NULL,s2,-1,j);
            j--;
        }

        if(!ans) puts("No carry operation.");
        else printf("%d carry operation%s.\n",ans,(ans == 1) ? "" : "s");
    }
    return 0;   
}
