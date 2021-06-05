#include <cstdio>
using namespace std;

int main()
{
    int i,N,ans;
    char c,A[105];
    bool ok;

    ans = 0;
    scanf("%d",&N);
    while(N--)
    {
        scanf("%s",A);
        i = 0;
        ok = true;
        int B[26] = {};

        while((c = A[i++]))
        {
            if(c != A[i])
            {
                B[c-'a']++;
                c = A[i];
            }
        }

        for(i = 0; i < 26; i++)
            if(B[i] > 1)
                ok = false;
        
        ans += ok ? 1 : 0;
    }

    printf("%d\n",ans);
    return 0;    
}
