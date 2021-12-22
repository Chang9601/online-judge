import java.util.*;

class Solution {
    public int solution(String s) {
        String[] nums = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
		int len = s.length();
		int i = 0, j = 0, idx = 0;
		int num = 0;
		String sub = "";

		while(i < len){
			if(Character.isDigit(s.charAt(i))){
				num = num*10+(s.charAt(i)-'0');
				i++;
			}else{
                for(j = 0; j < nums.length; j++){
					idx = s.indexOf(nums[j], i);
					if(idx == i){
						sub = nums[j];
                        			break;
					}
                }
				num = num*10+j;    
				i += sub.length();
			}
		}
        return num;
    }
}
