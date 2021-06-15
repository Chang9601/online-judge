#include <cstdio>
#include <queue>
#include <vector>
#include <map>
using namespace std;

int main()
{
    int i,j,idx,N,M,u,v;
    char s[105][55];
    char s1[55],s2[55];

    idx = 1;
    while(scanf("%d",&N) == 1)  
    {
        vector<string> ans;
        priority_queue<int, vector<int>, greater<int>> pq; 
        map<string,int> m;
        vector<int> adj[105];
        int deg[105] = {};

        for(i = 0; i < N; i++)
        {
            scanf("%s",s[i]);
            m[s[i]] = i;
        }

        scanf("%d",&M);

        for(i = 0; i < M; i++)
        {
            scanf("%s",s1);
            scanf("%s",s2);
            u = m[s1]; v = m[s2];
            adj[u].push_back(v);
            deg[v]++;
        }

        for(i = 0; i < N; i++)
            if(!deg[i])
                pq.push(i);

        printf("Case #%d: Dilbert should drink beverages in this order:",idx++);
        while(!pq.empty())
        {
            u = pq.top();
            pq.pop();
            ans.push_back(s[u]);

            for(i = 0; i < (int)adj[u].size(); i++)
            {
                v = adj[u][i];
                if(--deg[v] == 0)
                    pq.push(v);
            }
            printf(" %s",s[u]);
        }

        puts(".\n");
    }
    return 0;    
}
