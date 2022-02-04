class Solution {
    public int solution(int n) {
        int ans = 0;
        
        for(int i = 1; i*i <= n; i++){
            if(n%i == 0){
                int j = n/i;            
                ans += i;
                if(i != j) ans += j;
            }
        }
        
        return ans;
    }
}
