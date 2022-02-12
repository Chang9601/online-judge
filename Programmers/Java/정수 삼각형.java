import java.util.*;

class Solution {
    public int solution(int[][] triangle) {
        int r = triangle.length;
        int c = triangle[r-1].length;
        int i,j;
        int[][] dp = new int[r][c];

        for(int[] d : dp) 
            Arrays.fill(d, -1);

        dp[0][0] = triangle[0][0];

        for(i = 1; i < r; i++){
            for(j = 0; j < triangle[i].length; j++){
                dp[i][j] = Math.max(dp[i][j],dp[i-1][j]+triangle[i][j]);
                if(j-1 >= 0) dp[i][j] = Math.max(dp[i][j],dp[i-1][j-1]+triangle[i][j]);
            }
        }

        int ans = -1;
        for(j = 0; j < c; j++) ans = Math.max(ans,dp[r-1][j]);
        return ans;
    }
}
