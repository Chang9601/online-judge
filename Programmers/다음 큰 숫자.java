class Solution {
    private int go(int num) {
        int cnt;
        for(cnt = 0; num != 0; num &= (num-1))
            cnt++;
        return cnt;
    }

    public int solution(int n) {
        int m = n+1;

        while(go(m) != go(n))
            m++;
        return m;
    }
}
