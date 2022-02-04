class Solution {
    public String solution(String new_id) {
        new_id = new_id.toLowerCase();
        new_id = new_id.replaceAll("[^a-z0-9-_.]","");	
    	  new_id = new_id.replaceAll("[.]{2,}",".");
    	  new_id = new_id.replaceAll("^[.]|[.]$",""); 
    	
        if(new_id.equals(""))
            new_id = "a";
        
        int len = new_id.length();
        if(len >= 16){
            new_id = new_id.substring(0,15);
            new_id = new_id.replaceAll("[.]$","");
        }
    
        len = new_id.length();
        if(len <= 2){
            char c = new_id.charAt(len-1);
            while(new_id.length() < 3)
                new_id += c;
        }
        
        return new_id;
    }
}
