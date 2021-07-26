#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

bool is_palindrome(char s[])
{
    int i,j;
    for(i = 0,j = strlen(s)-1; i < j; i++,j--)
        if(s[i] != s[j])
            return false;
    return true;
}

int main()
{
    int N;
    long long num,rev;
    char s[100];

    scanf("%d",&N);
    while(N--)
    {
        int ans,tmp,cnt;
        scanf("%lld",&num);

        ans = 0;
        while(1)
        {
            sprintf(s,"%lld",num);
            if(is_palindrome(s))
                break;

            tmp = num;
            cnt = rev = 0;
            do
            {
                cnt++;
                tmp /= 10;
            }while(tmp);
            
            tmp = num;
            do
            {
                rev += pow(10,--cnt)*(tmp%10);
                tmp /= 10;
            }while(tmp);
            
            num += rev;
            ans++;
        }

        printf("%d %lld\n",ans,num);
    }
    return 0;    
}
