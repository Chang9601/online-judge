#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;

int N,M;
struct CCTV{
    int x,y,t;
};
int grid[8][8],tmp[8][8];
CCTV P[8];
int D[8];
int num,ans;

void east(int idx)
{
    int x = P[idx].x; int y = P[idx].y;
    int j;

    for(j = y+1; j < M && tmp[x][j] != 6; j++)
    {
        if(tmp[x][j]) continue;
        tmp[x][j] = -1;
    }
}

void west(int idx)
{
    int x = P[idx].x; int y = P[idx].y;
    int j;

    for(j = y-1; j >= 0 && tmp[x][j] != 6; j--) 
    {
        if(tmp[x][j]) continue;
        tmp[x][j] = -1;
    }
}

void south(int idx)
{
    int x = P[idx].x; int y = P[idx].y;
    int i;

    for(i = x+1; i < N && tmp[i][y] != 6; i++)
    {   
        if(tmp[i][y]) continue;
        tmp[i][y] = -1;
    }
}

void north(int idx)
{
    int x = P[idx].x; int y = P[idx].y;
    int i;

    for(i = x-1; i >= 0 && tmp[i][y] != 6; i--) 
    {   
        if(tmp[i][y]) continue;
        tmp[i][y] = -1;
    }   
}

void one(int idx,int d)
{
    if(d == 0) east(idx);
    else if(d == 1) south(idx);
    else if(d == 2) west(idx);
    else north(idx);
}

void two(int idx,int d)
{
   
    if(d == 0 || d == 2)
    {
        east(idx); west(idx);
    }
    else
    {
        north(idx); south(idx);
    }
}

void three(int idx,int d)
{

    if(d == 0)
    {
        north(idx); east(idx);
    }
    else if(d == 1)
    {
        east(idx); south(idx);
    }
    else if(d == 2)
    {
        south(idx); west(idx);
    }
    else
    {
        west(idx); north(idx);
    }
}

void four(int idx,int d)
{
    
    if(d == 0)
    {
        west(idx); north(idx); east(idx);
    }
    else if(d == 1)
    {
        north(idx); east(idx); south(idx);
    }
    else if(d == 2)
    {
        east(idx); south(idx); west(idx);
    }
    else
    {
        south(idx); west(idx); north(idx);
    }
}

void five(int idx,int d)
{
    north(idx); east(idx);
    south(idx); west(idx);
}

int run()
{
    memcpy(tmp,grid,sizeof(grid)); int ct = 0;
    for(int i = 0; i < num; i++)
    {
        switch(P[i].t)
        {
            case 1: one(i,D[i]); break;
            case 2: two(i,D[i]); break;
            case 3: three(i,D[i]); break;
            case 4: four(i,D[i]); break;
            case 5: five(i,D[i]); break;
        }
    }

    int i,j;
    for(i = 0; i < N; i++)
        for(j = 0; j < M; j++)
            ct += (tmp[i][j] == 0) ? 1 : 0;
    return ct;
}

void go(int cnt)
{
    if(cnt == num)
    {
        int t = run();
        ans = min(ans,t);
        return;
    }

    D[cnt] = 0;
    go(cnt+1);
    D[cnt] = 1;
    go(cnt+1);
    D[cnt] = 2;
    go(cnt+1);
    D[cnt] = 3;
    go(cnt+1);
}

int main()
{   
    scanf("%d %d",&N,&M); int i,j; num = 0;
    for(i = 0; i < N; i++)
        for(j = 0; j < M; j++)
        {
            scanf("%d",&grid[i][j]);
            if(grid[i][j] != 0 && grid[i][j] != 6) 
            {
                P[num].x = i; P[num].y = j; P[num].t = grid[i][j];
                num++;
            }
        }

    ans = 1e9;
    go(0);

    printf("%d\n",ans);
    return 0;
}
