import java.util.*;

class Solution {
    public int[] solution(int n, String[] words) {
        HashMap<String,Integer> m;
        int i,cnt,size;
        char c;
        int[] ans;
        
        m = new HashMap<String,Integer>();
        cnt = 0;
        size = words.length;
        c = words[0].charAt(words[0].length()-1);
        ans = new int[2];
        
        for(i = 0; i < size; i++){
            if(i%n == 0) cnt++;
            
            if(i-1 >= 0) c = words[i-1].charAt(words[i-1].length()-1);
            
            if(m.containsKey(words[i]) || (i-1 >= 0 && c != words[i].charAt(0))){
                ans[0] = (i%n)+1;
                ans[1] = cnt;
                break;    
            }
            
            m.put(words[i],1);
        }
        
        return ans;
    }
}
