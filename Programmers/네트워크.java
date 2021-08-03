class Solution {
    
    public class DSU{
        int[] r;
        int[] p;
        
        public void init(int n){
            r = new int[n+1];
            p = new int[n+1];
            
            for(int i = 1; i <= n; i++){
                r[i] = 1;
                p[i] = i;
            }
        }
        
        public int find(int u){
            if(u == p[u]) return u;
            return p[u] = find(p[u]);
        }
        
        public boolean merge(int u,int v){
            u = find(u); v = find(v);
            
            if(u == v) return false;
            
            if(r[u] > r[v]){
                r[u] += r[v];
                p[v] = u;
            }else{
                r[v] += r[u];
                p[u] = v;
            }
            
            return true;
        }
    }
    
    public int solution(int n, int[][] computers) {
        int ans,i,j,r,c;
        DSU d;
        
        d = new DSU();
        d.init(n);
        r = computers.length;
        c = computers[0].length;
        ans = n;
        
        for(i = 0; i < r; i++){
            for(j = 0; j < c; j++){
                if(computers[i][j] == 1)
                    if(d.merge(i+1,j+1)) ans--;
            }
        }
    
        return ans;
    }
}
