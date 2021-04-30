#include <cstdio>
using namespace std;
int T,D,Q,P;
struct Maker{
    int L,H;
    char M[25];
};
Maker A[10005];

int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&D);
        int i,j,cnt,idx;
        for(i = 0; i < D; i++)
            scanf("%s %d %d",A[i].M,&A[i].L,&A[i].H);
        scanf("%d",&Q);
        while(Q--)
        {
            cnt = 0;
            scanf("%d",&P);
            for(i = 0; i < D; i++)
                if(A[i].L <= P && P <= A[i].H)
                {
                    cnt++;
                    idx = i;
                }
            if(cnt > 1 || cnt == 0)
                puts("UNDETERMINED");
            else
                printf("%s\n",A[idx].M);
        }
        if(T)
            putchar('\n');
    }
    return 0;    
}
