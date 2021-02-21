#include <cstdio>
#include <cmath>
using namespace std;
#define INF 1000000000
int N,M;
bool chosen[13];
int A[13];
//int grid[50][50];
int num_chicken,num_house;
struct Point{
    int x,y;
};
Point H[105],C[13];
int ans;

int run(int num)
{
    int i,j; int dis,mn; int sum = 0;
    for(i = 0; i < num_house; i++)
    {
        mn = INF;
        for(j = 0; j < num; j++)
        {
            dis = abs(H[i].x-C[A[j]].x)+abs(H[i].y-C[A[j]].y);
            mn = min(mn,dis);
        }
        sum += mn;
    }
    return sum;
}

void go(int cnt,int idx)
{
    if(cnt == M)
    {
        int d = run(cnt);
        ans = min(ans,d);
        return;
    }

    for(int i = idx; i < num_chicken; i++)
    {
        if(chosen[i]) continue;
        chosen[i] = true;
        A[cnt] = i;
        go(cnt+1,i);
        chosen[i] = false;
    }
}

int main()
{   
    scanf("%d %d",&N,&M); ans = INF; int i,j,x;
    for(i = 0; i < N; i++)
        for(j = 0; j < N; j++)
        {
            scanf("%d",&x);
            if(x == 1)
            {
                H[num_house].x = i; H[num_house].y = j;
                num_house++;
            }
            else if(x == 2)
            {
                C[num_chicken].x = i; C[num_chicken].y = j;
                num_chicken++;
            }
            
        }

    go(0,0);
    printf("%d\n",ans);
    return 0;
}
