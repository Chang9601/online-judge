#include <cstdio>
#include <cstdlib>
using namespace std;

struct Edge{
    int u,v;
    int c;
};

struct DSU{
    int r[200005],p[200005];
    
    void init_dsu(int n)
    {
        int i;
        for(i = 0; i < n; i++)
        {
            r[i] = 1;
            p[i] = i;
        }
    }
    
    int find_parent(int u)
    {
        if(u == p[u])
            return u;
        return p[u] = find_parent(p[u]);
    }
    
    int merge_dsu(int u,int v)
    {
        u = find_parent(u); v = find_parent(v);
        
        if(u == v)
            return 0;
            
        if(r[v] < r[u])
        {
            r[u] += r[v];
            p[v] = u;
        }
        else
        {
            r[v] += r[u];
            p[u] = v;
        }
        return 1;
    }
};

int cmp(const Edge *a,const Edge *b)
{
    if(a->c < b->c)
        return -1;
    else if(a->c > b->c)
        return 1;
    else
        return 0;
}

int main() {
   int m,n;
   
   while(scanf("%d %d",&m,&n))
   {
       if(!m && !n)
           break;
           
        DSU d;
        Edge A[200005];
        int ans,sum;
        int i,u,v,c;
  
        ans = sum = 0; 
        d.init_dsu(m);
        
        for(i = 0; i < n; i++)
        {
            scanf("%d %d %d",&u,&v,&c);
            A[i].u = u; A[i].v = v;
            A[i].c = c; sum += c;
        }
   
        qsort(A,n,sizeof(A[0]),(int(*)(const void*,const void*))cmp);
        for(i = 0; i < n; i++)
            if(d.merge_dsu(A[i].u,A[i].v))
                ans += A[i].c;
            
        printf("%d\n",sum-ans);
   }
   
   return 0;
}
