import java.util.*;
import java.lang.*;

class Solution {
    public int[] solution(int[] answers) {
        List<Integer> list = new ArrayList<>();
        int[] one = {1,2,3,4,5};
        int[] two = {2,1,2,3,2,4,2,5};
        int[] three = {3,3,1,1,2,2,4,4,5,5};
        int[] n = new int[3];
        int l1,l2,l3;
        int n1,n2,n3;
        int max;

        l1 = one.length;
        l2 = two.length;
        l3 = three.length;

        for(int i = 0; i < answers.length; i++){
            n[0] += one[i%l1] == answers[i] ? 1 : 0;   
            n[1] += two[i%l2] == answers[i] ? 1 : 0;              
            n[2] += three[i%l3] == answers[i] ? 1 : 0; 
        }

        max = -1;
        max = Math.max(n[0],n[1]);
        max = Math.max(max,n[2]);

        for(int i = 0; i < 3; i++)
            if(max == n[i])
                list.add(i);

        int[] ans = new int[list.size()];
        for(int i = 0; i < list.size(); i++)
            ans[i] = list.get(i)+1;

        return ans;
    }
}
