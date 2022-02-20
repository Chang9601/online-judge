import java.util.*;

class Solution {
    
    private static void go(String word,String vowels,int idx,List<String> l){
        if(idx > vowels.length()) return;
        l.add(word);
        
        for(int i = 0; i < vowels.length(); i++)
            go(word+vowels.charAt(i),vowels,idx+1,l);
    }
    
    public int solution(String word) {
        List<String> l = new ArrayList();
        String vowels = "AEIOU";
        
        go("",vowels,0,l);
   
        return l.indexOf(word);
    }
}
