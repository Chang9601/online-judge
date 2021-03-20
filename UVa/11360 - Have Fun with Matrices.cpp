#include <cstdio>
#include <algorithm>
using namespace std;
#define INF 1000000000
int T,N,M;
int grid[55][55];
int buf[55];

void row(int a,int b)
{
    int j; 
    --a; --b;
    for(j = 0; j < N; j++) swap(grid[a][j],grid[b][j]);
}

void col(int a,int b)
{
    int i;
    --a; --b;
    for(i = 0; i < N; i++) swap(grid[i][a],grid[i][b]);
}

void transpose()
{
    int i,j;
    for(i = 0; i < N; i++)
        for(j = 0; j < i; j++)
            swap(grid[i][j],grid[j][i]);
}

void inc()
{
    int i,j;
    for(i = 0; i < N; i++)
        for(j = 0; j < N; j++)
            grid[i][j] = (grid[i][j]+1)%10;
}

void dec()
{
    int i,j;
    for(i = 0; i < N; i++)
        for(j = 0; j < N; j++)
            grid[i][j] = (grid[i][j]+10-1)%10;
}

int main()
{
    int idx = 1; scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&N); int i,j; char s[20]; int a,b; char cmd[10];
        for(i = 0; i < N; i++)
            for(j = 0; j < N; j++)
                scanf("%1d",&grid[i][j]);
        
        scanf("%d",&M);
      
        while(M--)
        {
            scanf("%s",s);
            switch(s[0])
            {
                case 'r':
                    scanf("%d %d",&a,&b);
                    row(a,b);
                    break;
                case 'c':
                    scanf("%d %d",&a,&b);
                    col(a,b);
                    break;
                case 'i':
                    inc();
                    break;
                case 'd':
                    dec();
                    break;
                case 't':
                    transpose();
                    break;
            }
        }

        printf("Case #%d\n",idx++);
        for(i = 0; i < N; i++,puts(""))
          for(j = 0; j < N; j++)
                printf("%d",grid[i][j]);
        puts("");
    }
    return 0;   
}
