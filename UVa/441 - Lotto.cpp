#include <cstdio>
#include <cstring>
using namespace std;

void go(int k,int S[],int lim,int cnt,int idx,int A[],bool chosen[])
{
    if(cnt == lim)
    {
        for(int i = 0; i < cnt; i++)
            printf("%d%s",A[i],(i != cnt-1) ? " " : "\n");
        return;
    }

    for(int i = idx; i < k; i++)
    {
        if(chosen[i])
            continue;
        chosen[i] = true;
        A[cnt] = S[i];
        go(k,S,lim,cnt+1,i,A,chosen); 
        chosen[i] = false;
    }
}

int main()
{
    int k,i,cnt;
    int S[13],A[13];
    bool chosen[13];

    cnt = 0;
    while(scanf("%d",&k) == 1 && k)
    {
        if(cnt) 
            puts("");
        cnt = 1; 

        memset(chosen,false,sizeof(chosen));
        for(i = 0; i < k; i++)
            scanf("%d",&S[i]);
        go(k,S,6,0,0,A,chosen);
    }

    return 0;    
}
