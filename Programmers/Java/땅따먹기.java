class Solution {
    int solution(int[][] land) {
        int ans = -1;
        int mx = -1;
        int r = land.length;
        int[][] dp = new int[r][4];
        
        for(int i = 0; i < r; i++){
            for(int j = 0; j < 4; j++) {
                if(i == 0)
                    dp[i][j] = land[i][j];
                for(int k = 0; k < 4; k++) {
                    if(i-1 >= 0 && j != k)
                        dp[i][j] = Math.max(dp[i][j],land[i][j]+dp[i-1][k]);
                }
            }
        }
        
        for(int j = 0; j < 4; j++)
            ans = Math.max(ans,dp[r-1][j]);
        
        return ans;
    }
}
