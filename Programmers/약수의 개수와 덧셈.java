class Solution {
    public int solution(int left, int right) {
        int ans,i;
        
        ans = 0;
        for(i = left; i <= right; i++)
            ans += calculateFactors(i)%2 == 0 ? i : -i;
        
        return ans;
    }
    
    public int calculateFactors(int n){
        int i,x,y,ans;
        
        ans = 0;
        for(i = 1; i*i <= n; i++){
            if(n%i == 0){
                x = n/i;
                y = n/x;
                
                ans++;
                if(x != y) ans++;
            }
        }
        
        return ans;
    }
}
