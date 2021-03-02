#include <cstdio>
#include <cstring>
using namespace std;
int A[5][8];
int K;
bool vis[5];

void clock(int idx)
{
    int t = A[idx][7];
    int i;
    for(i = 7; i > 0; i--)
        A[idx][i] = A[idx][i-1];
    A[idx][0] = t;
}

void cclock(int idx)
{
    int t = A[idx][0];
    int i;
    for(i = 0; i < 7; i++)
        A[idx][i] = A[idx][i+1];
    A[idx][7] = t;
}

void go(int idx,int d)
{
    if(idx < 1 || idx > 4) return;
    if(vis[idx]) return;
    vis[idx] = true;

    if(A[idx][2] != A[idx+1][6]) go(idx+1,-1*d);
    if(A[idx][6] != A[idx-1][2]) go(idx-1,-1*d);

    if(d == 1) clock(idx);  
    else cclock(idx);
}

int main()
{   
    int i,j,ans = 0;
    for(i = 1; i <= 4; i++)
        for(j = 0; j < 8; j++)
            scanf("%1d",&A[i][j]);

    scanf("%d",&K);
    while(K--)
    {
        int idx,d; memset(vis,false,sizeof(vis));
        scanf("%d %d",&idx,&d);
        go(idx,d);
    }   

    for(i = 1; i <= 4; i++)
        ans += (A[i][0]) ? (1 << (i-1)) : 0;
    printf("%d\n",ans);
    return 0;
}
