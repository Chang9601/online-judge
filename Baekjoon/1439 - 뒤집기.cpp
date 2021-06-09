#include <iostream>
using namespace std;

int main() {
    char s[1000005];
    char c;
    int i,num,num2,cnt,ans;
    
    scanf("%s",s);
    i = 0;
    num = cnt = 0;
    while((c = s[i++])) 
    {
        if(c != s[i])
        {
            if(c == '1')
                num++;
            c = s[i];
            cnt++;
        }
    }
    num2 = cnt-num; 
    ans = min(num,num2);
    
    printf("%d",ans);
    return 0;
}
