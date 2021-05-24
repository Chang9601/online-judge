#include <cstdio>
using namespace std;
struct DSU{
    int r[30],p[30];
    int num;

    void init_dsu(int n)
    {
        int i;
        for(i = 1; i <= n; i++)
        {
            r[i] = 1;
            p[i] = i;
        }
        num = n;
    }

    int find_parent(int u)
    {
        if(p[u] == u)
            return u;
        return p[u] = find_parent(p[u]);
    }

    int merge_dsu(int u,int v)
    {
        u = find_parent(u); v = find_parent(v);

        if(u == v)
            return 0;
        
        if(r[u] < r[v])
        {
            r[v] += r[v];
            p[u] = v;
        }
        else
        {
            r[u] += r[v];
            p[v] = u;
        }
        num--;
        return 1;
    }
};

void clear_input_buffer()
{
    while(getchar() != '\n')
        ;
}

void delete_newline(char s[])
{
    int i;
    i = 0;

    while(s[i] != '\n')
        i++;
    s[i] = '\0';
}

int main()
{
    int T;
    scanf("%d ",&T);
    while(T--)
    {
        DSU A;
        char c;
        char s[10];
        int mx,u,v;
        scanf("%c",&c);
        mx = c-'A'+1;
        A.init_dsu(mx);

        clear_input_buffer();
        while(fgets(s,sizeof(s),stdin))
        {
            delete_newline(s);
            if(s[0] == '\0')
                break;
            u = s[0]-'A'+1; v = s[1]-'A'+1;
            A.merge_dsu(u,v);
        }

        printf("%d\n",A.num);
        if(T)
            putchar('\n');
    }
    return 0;    
}
