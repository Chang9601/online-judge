import java.lang.*;

class Solution {
    public long solution(long n) {
        double sqrt = Math.sqrt(n);
        long lsqrt = (long)sqrt;
        long ans;

        if(sqrt == lsqrt) ans = (lsqrt+1)*(lsqrt+1);
        else ans = -1;

        return ans;
    }
}
