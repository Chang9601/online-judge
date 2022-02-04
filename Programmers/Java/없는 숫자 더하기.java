class Solution {
    public int solution(int[] numbers) {
        int ans = 45;
        for(int num : numbers) ans -= num;

        return ans;
    }
}
