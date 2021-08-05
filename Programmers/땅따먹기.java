class Solution {
    int solution(int[][] land) {
        int i,j,k,r,ans;
        int[][] dp;

        r = land.length;
        dp = new int[r][4];

        for(j = 0; j < 4; j++)
            dp[0][j] = land[0][j];

        for(i = 1; i < r; i++){
            for(j = 0; j < 4; j++){
                for(k = 0; k < 4; k++){
                    if(j == k) continue;
                    dp[i][j] = Math.max(dp[i][j],dp[i-1][k]+land[i][j]);
                }
            }
        }

        ans = -1;
        for(j = 0; j < 4; j++)
            ans = Math.max(ans,dp[r-1][j]);

        return ans;
    }
}
