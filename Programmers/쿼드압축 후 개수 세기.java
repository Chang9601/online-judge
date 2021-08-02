class Solution {
    public int[] solution(int[][] arr) {
        int[] ans;
        int n;
        
        n = arr.length;
        ans = new int[2];
        go(ans,arr,0,0,n);
        
        return ans;
    }
    
    private void go(int[] ans,int[][] arr,int x,int y,int n){
        if(isAllSame(arr,x,y,n)){
            ans[0] += (arr[x][y] == 0) ? 1 : 0;
            ans[1] += (arr[x][y] == 1) ? 1 : 0;
            return;
        }
        
        go(ans,arr,x,y,n/2);
        go(ans,arr,x+n/2,y,n/2);
        go(ans,arr,x,y+n/2,n/2);
        go(ans,arr,x+n/2,y+n/2,n/2);
    }
    
    private boolean isAllSame(int[][] arr,int x,int y,int n){
        int i,j;
        
        for(i = x; i < x+n; i++)
            for(j = y; j < y+n; j++)
                if(arr[x][y] != arr[i][j])
                    return false;
        return true;
    }
}
