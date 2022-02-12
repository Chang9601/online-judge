class Solution {
    public int solution(int[] numbers, int target) {
        int ans = 0;
        int size = numbers.length;

        for(int i = 0; i < 1 << size; i++){
            int sum = 0;
            for(int j = 0; j < size; j++){
                if(((i >> j) & 1) == 1) sum += numbers[j];
                else sum -= numbers[j];
            }
            if(sum == target) ans++;
        }
        return ans;
    }
}
