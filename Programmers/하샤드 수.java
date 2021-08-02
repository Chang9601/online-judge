class Solution {
    public boolean solution(int x) {
        int t,n;

        n = 0;
        t = x;
        do{
            n += t%10;
            t /= 10;
        }while(t > 0);

        return x%n == 0;
    }
}
