import java.util.*;

class Solution {
    public int solution(String begin, String target, String[] words) {
        Queue<String> q;
        HashMap<String,Integer> m;
        String u,v;
        int i,j,size1,size2,cnt;

        size1 = words.length;
        q = new LinkedList<String>();
        m = new HashMap<String,Integer>();

        q.add(begin);
        m.put(begin,0);
        while(!q.isEmpty()){
            u = q.poll();

            for(i = 0; i < size1; i++){
                v = words[i];
                cnt = 0;
                size2 = v.length();

                if(v != u && m.containsKey(v)) continue;

                for(j = 0; j < size2; j++)
                    cnt += (u.charAt(j) != v.charAt(j)) ? 1 : 0;

                if(cnt == 1){
                    q.add(v);
                    m.put(v,m.get(u)+1);
                }
            }
        }

        return m.containsKey(target) ? m.get(target) : 0;
    }
}
