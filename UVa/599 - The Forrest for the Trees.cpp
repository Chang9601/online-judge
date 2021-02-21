#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
int t;
vector<int> adj[26];
bool vis[26];
int flag,area;

void dfs(int here,int prev)
{
    if(vis[here])
    {
        flag = 1;
        return;
    }
    vis[here] = true;
    area++;

    for(int i = 0; i < (int)adj[here].size(); i++)
    {
        int next = adj[here][i];
        if(next == prev) continue;
        dfs(next,here);
    }
}

int main()
{
    scanf("%d ",&t);
    while(t--)
    {
        char s[60]; int a = 0,b = 0; bool has[26] = {};
        memset(vis,false,sizeof(vis));

        for(int i = 0; i < 26; i++) adj[i].clear();

        while(gets(s))
        {
            if(s[0] == '*') break;
            int v = s[1]-'A'; int u = s[3]-'A';
            adj[v].push_back(u); adj[u].push_back(v);
        }
        gets(s);
        for(int i = 0; i < strlen(s); i += 2) has[s[i]-'A'] = true;
        for(int i = 0; i < 26; i++)
        {
            if(!has[i]) continue;
            flag = area = 0;
            dfs(i,-1);
            if(area == 1) b++;
            else if(!flag) a++;
        }
        printf("There are %d tree(s) and %d acorn(s).\n",a,b);
      //  puts("");
    }

    return 0;
}
