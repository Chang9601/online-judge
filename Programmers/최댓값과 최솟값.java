class Solution {
    public String solution(String s) {
        String ans;
        String[] arr = s.split(" ");
        long mn,mx,num;

        mn = mx = Long.parseLong(arr[0]);
        for(String e:arr){
            num = Long.parseLong(e);
            mn = Math.min(mn,num);
            mx = Math.max(mx,num);
        }

        ans = "";
        ans += String.valueOf(mn);
        ans += " ";
        ans += String.valueOf(mx);

        return ans;
    }
}
