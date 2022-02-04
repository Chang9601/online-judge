import java.util.*;

class Solution {
    public String[] solution(String[] record) {
        Map<String, String> m = new HashMap<>();
        List<String> arr = new ArrayList<>();
        int i;

        for(String r : record){
            String[] tokens = r.split(" ");

            switch(tokens[0]){
                case "Enter":
                    m.put(tokens[1], tokens[2]); // <ID, NAME> 삽입
                    arr.add(tokens[1]+"님이 들어왔습니다."); // ID로 저장
                    break;
                case "Leave":
                    arr.add(tokens[1]+"님이 나갔습니다.");
                    break;
                case "Change":
                    m.put(tokens[1], tokens[2]); // <ID, NAME> 갱신
                    break;
            }
        }

        String[] ans = new String[arr.size()];
        i = 0;

        for(String s : arr){
            int index = s.indexOf("님");
            String sub = s.substring(0,index);
            s = s.replaceAll(sub,m.get(sub));

            ans[i++] = s;
        }

        return ans;
    }
}
