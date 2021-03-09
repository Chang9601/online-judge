#include <cstdio>
#include <cmath>
using namespace std;
#define INF 1000000000000000000LL
int n,m,q;
long long dis[505][505];

int main()
{
    scanf("%d %d %d",&n,&m,&q);
    int i,j,k; int a,b; long long w;
    for(i = 1; i <= n; i++)
        for(j = 1; j <= n; j++)
        {
            if(i == j) dis[i][j] = dis[j][i] = 0;
            else dis[i][j] = dis[j][i] = INF;
        }

    while(m--)
    {
        scanf("%d %d %lld",&a,&b,&w);
        dis[a][b] = min(dis[a][b],w);
        dis[b][a] = min(dis[b][a],w);
    }

    for(k = 1; k <= n; k++)
        for(i = 1; i <= n; i++)
            for(j = 1; j <= n; j++)
                dis[i][j] = min(dis[i][j],dis[i][k]+dis[k][j]);
    while(q--)
    {
        scanf("%d %d",&a,&b);
        if(dis[a][b] == INF || dis[b][a] == INF) puts("-1");
        else printf("%lld\n",dis[a][b]);
    }
    return 0;   
}
