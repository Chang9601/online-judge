import java.util.Arrays;   

class Solution {
    public int solution(int[] d, int budget) {
        int ans;
        int i;

        ans = 0;
        Arrays.sort(d);
        for(i = 0; i < d.length; i++)
            if(d[i] <= budget){
                ans++;
                budget -= d[i];
            }

        return ans;
    }
}
