class Solution {
    public int solution(int[] absolutes, boolean[] signs) {
        int ans;
        int i,size;

        ans = 0;
        size = signs.length;
        for(i = 0; i < size; i++)
            ans += absolutes[i]*(signs[i] == true ? 1 : -1);

        return ans;
    }
}
