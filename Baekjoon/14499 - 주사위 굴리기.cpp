#include <cstdio>
#include <cstring>
using namespace std;
int N,M,K;
int A[6],buf[6];
int x,y;
int grid[25][25];

bool is_bound(int i,int j)
{
    if(i >= 0 && i < N && j >= 0 && j < M) return true;
    return false;
}

void update(int i,int j)
{
    if(grid[i][j] == 0) grid[i][j] = A[1];
    else
    {
        A[1] = grid[i][j];
        grid[i][j] = 0;
    }
}

void east()
{
    memcpy(buf,A,sizeof(A));
    A[0] = buf[5]; A[1] = buf[4];
    A[4] = buf[0]; A[5] = buf[1];
}

void west()
{
    memcpy(buf,A,sizeof(A));
    A[1] = buf[5]; A[0] = buf[4];
    A[5] = buf[0]; A[4] = buf[1];
}

void south()
{
    memcpy(buf,A,sizeof(A));
    A[2] = buf[0]; A[3] = buf[1];
    A[1] = buf[2]; A[0] = buf[3];  
}

void north()
{
    memcpy(buf,A,sizeof(A));
    A[3] = buf[0]; A[2] = buf[1];
    A[0] = buf[2]; A[1] = buf[3];
}

int main()
{   
    scanf("%d %d %d %d %d",&N,&M,&x,&y,&K); int i,j,c;
    for(i = 0; i < N; i++)
        for(j = 0; j < M; j++)
            scanf("%d",&grid[i][j]);
    
    while(K--)
    {  
        scanf("%d",&c);

        switch(c)
        {
            case 1: 
                if(is_bound(x,y+1))
                {
                    y++;
                    east(); update(x,y);
                    printf("%d\n",A[0]);
                }
                break;
            case 2: 
                if(is_bound(x,y-1))
                {
                    y--;
                    west(); update(x,y);
                    printf("%d\n",A[0]);
                }
                break;
            case 3: 
                if(is_bound(x-1,y)) 
                {
                    x--;
                    north(); update(x,y);
                    printf("%d\n",A[0]);
                }
                break;
            case 4: 
                if(is_bound(x+1,y))
                {
                    x++;
                    south(); update(x,y);
                    printf("%d\n",A[0]);
                }
                break;
        }
    }
    return 0;
}
