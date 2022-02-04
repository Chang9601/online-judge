import java.util.*;

class Solution {
    boolean solution(String s) {
        Stack<Character> stk = new Stack<>();
        int i;

        for(i = 0; i < s.length(); i++){
            if(s.charAt(i) == '(') 
                stk.push('(');
            else{
                if(stk.empty() || stk.peek() != '(' )
                    return false;
                stk.pop();
            }
        }

        return stk.empty();
    }
}
