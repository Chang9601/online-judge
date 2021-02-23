#include <cstdio>
#include <queue>
using namespace std;
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};
char grid[6][6];
bool chosen[25];
int A[25];
int ans;
struct Party{
    int x,y;
};
Party P[25];

bool run()
{
    queue<int> q; int cnt = 1;
   // int x,y;
   // x = A[0]/5; y = A[0]%5;
    q.push(A[0]);
    bool vis[5][5] = {0,};
    vis[A[0]/5][A[0]%5] = true;

    while(!q.empty())
    {
       // int x = q.front().x; int y = q.front().y;
        int p = q.front(); q.pop();
        int x = p/5; int y = p%5;
       // q.pop();

        for(int i = 0; i < 4; i++)
        {
            int nx = x+dx[i]; int ny = y+dy[i];
            int num = nx*5+ny;
            if(nx < 0 || nx >= 5 || ny < 0 || ny >= 5) continue;
            if(!chosen[num]) continue;
            if(vis[nx][ny]) continue;

            vis[nx][ny] = true;
            q.push(num);
            cnt++;
        }
    }
    return (cnt == 7) ? true : false;
}

void go(int cnt,int idx,int Y,int S)
{
    if(cnt == 7)
    {
        if(S >= 4)
        {
            bool ok = run();
            ans += ok;
        }
        return;
    }

    for(int i = idx; i < 25; i++)
    {
        if(chosen[i]) continue;
        chosen[i] = true;
        A[cnt] = i;
        int x = i/5; int y = i%5;
        if(grid[x][y] == 'S') go(cnt+1,i,Y,S+1);
        else go(cnt+1,i,Y+1,S);
        chosen[i] = false;
    }
}

int main()
{   
    int i;
    for(i = 0; i < 5; i++) scanf("%s",grid[i]);
    ans = 0;
    go(0,0,0,0); 
    printf("%d\n",ans);
    return 0;
}
