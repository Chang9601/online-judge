#include <cstdio>
#include <utility>
using namespace std;
int main()
{
    char s[1000005];
    char c;
    int n,i,j,a,b,idx;
    bool flag;

    idx = 1;
    while(scanf("%s",s) == 1)
    {
        if(s[0] == '\0')
            break;

        scanf("%d",&n);
        
        printf("Case %d:\n",idx++);
        while(n--)
        {
            scanf("%d %d",&a,&b);

            flag = true;
            if(a > b)
                swap(a,b);
            c = s[a];

            for(i = a; i <= b; i++)
                if(c != s[i])
                {
                    flag = false;
                    break;
                }

            printf("%s\n",flag ? "Yes" : "No");
        }     
    }
    return 0;    
}
