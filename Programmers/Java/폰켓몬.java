import java.util.*;

class Solution {
    public int solution(int[] nums) {
        int ans = 0;
        int last = -1;
        int len = nums.length/2;

        Arrays.sort(nums);

        for(int n : nums){
            if(last != n){
                last = n;
                if(ans < len)
                    ans++;
            }
        }

        return ans;
    }
}
