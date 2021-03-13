#include <cstdio>
using namespace std;
#define INF 10000000000000000LL
int l[100005],r[100005];
int B,S,L,R;

int main()
{
    while(scanf("%d %d",&S,&B) == 2)
    {
        int i;
        if(!B && !S) break;

        for(i = 1; i <= S; i++)
        {
            l[i] = i-1;
            r[i] = i+1;
        }
        l[1] = r[S] = -1;

        while(B--)
        {
            scanf("%d %d",&L,&R);
            r[l[L]] = r[R]; l[r[R]] = l[L];
            
            if(l[L] == -1) putchar('*');
            else printf("%d",l[L]);

            if(r[R] == -1) printf(" *");
            else printf(" %d",r[R]);
            puts("");
        }
        puts("-");
    }   
    return 0;   
}
