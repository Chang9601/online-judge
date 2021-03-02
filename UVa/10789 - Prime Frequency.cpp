#include <cstdio>
using namespace std;
int T;
char s[2005];

bool is_prime(int x)
{
    int i;
    if(x == 1) return false;
    for(i = 2; i*i <= x; i++)
        if(x%i == 0) return false;
    return true;
}

void quick(int A[],int l,int h)
{
    int pl = l;
    int ph = h;
    int pc = l+(h-l)/2;
    int x = A[pc];

    do
    {
        while(A[pl] < x) pl++;
        while(A[ph] > x) ph--;

        if(pl <= ph)
        {
            int t = A[pl];
            A[pl] = A[ph];
            A[ph] = t;
            pl++; ph--;
        }
    }while(pl <= ph);

    if(l < ph) quick(A,l,ph);
    if(pl < h) quick(A,pl,h);
}

int main()
{   
    scanf("%d",&T); int idx = 1;
    while(T--)
    {
        scanf("%s",s); int ASCII[128] = {};
        int i,j; int ans[128]; int cnt = 0;

        for(i = 0; s[i]; i++) ASCII[(int)s[i]]++;

        for(i = 0; i < 128; i++)
        {
            if(!ASCII[i]) continue;
            if(is_prime(ASCII[i])) ans[cnt++] = i;
        }

        quick(ans,0,cnt-1);
        printf("Case %d: ",idx++);
        for(i = 0; i < cnt; i++) printf("%c",(char)ans[i]);
        if(!cnt) printf("empty");
        putchar('\n'); 
    }
    return 0;
}
