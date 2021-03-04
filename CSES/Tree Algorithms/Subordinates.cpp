#include <cstdio>
#include <vector>
using namespace std;
vector<int> adj[200005];
int child[200005];

void dfs(int here,int prev)
{
    child[here] = 1;
    for(int i = 0; i < adj[here].size(); i++)
    {
        int next = adj[here][i];
        if(next == prev) continue;
        dfs(next,here);
        child[here] += child[next];
    }
}

int main()
{   
    int i,j,N,u,v;
    scanf("%d",&N);
    for(j = 2; j <= N; j++)
    {
        scanf("%d",&u);
        adj[u].push_back(j);
    }

    dfs(1,0);
    for(i = 1; i <= N; i++) printf("%d ",child[i]-1);
    return 0;
}
