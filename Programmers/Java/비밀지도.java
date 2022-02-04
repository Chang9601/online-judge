class Solution {
    public String[] solution(int n, int[] arr1, int[] arr2) {
        String[] ans = new String[n];

        for(int i = 0; i < n; i++){
            int sum = arr1[i] | arr2[i];
            String str = "";
            StringBuilder tmp = new StringBuilder();

            for(int x = 0; x < n; x++){
                if(((sum >> x) & 1) == 1) str += "#";
                else str += " ";
            }

            tmp.append(str);
            tmp.reverse();
            ans[i] = tmp.toString();
        }

        return ans;
    }
}
