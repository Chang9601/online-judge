class Solution {
    public int solution(int[] a, int[] b) {
        int i,size;
        int ans;
        
        ans = 0;
        size = a.length;
        for(i = 0; i < size; i++)
            ans += a[i]*b[i];
        
        return ans;
    }
}
