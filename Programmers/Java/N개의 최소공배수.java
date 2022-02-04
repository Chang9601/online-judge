class Solution {
    
    static private int gcd(int a, int b) {
       return b == 0 ? a : gcd(b,a%b);
    }
    
    static private int lcm(int a, int b) {
        return a/gcd(a,b)*b;
    }
    
    public int solution(int[] arr) {
        int ans = 1;
        for(int num : arr)
            ans = lcm(ans,num);
        return ans;
    }
}
