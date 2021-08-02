class Solution {
    public int[] solution(int[] arr) {
        int idx,mn,size;
        int ans[];

        idx = 0;
        size = arr.length;
        mn = arr[0];

        for(int n:arr)
            mn = Math.min(n,mn);
        ans = new int[(size == 1) ? 1 : size-1];

        for(int n:arr){
            if(n == mn) continue;
            ans[idx++] = n;
        }

        if(size == 1) ans[0] = -1;

        return ans;
    }
}
