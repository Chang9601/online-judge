class Solution {

    class Helper {
        int m;
        int n;
        boolean[][] visited;
        int[][] picture;
    }

    static int dfs(int x,int y,int area,Helper h){
        if(x >= h.m || x < 0 || y >= h.n || y < 0) return 0;
        if(h.visited[x][y]) return 0;
        if(h.picture[x][y] != area) return 0;

        int ans = 1;
        h.visited[x][y] = true;
        return ans + dfs(x-1,y,area,h) + dfs(x+1,y,area,h) + dfs(x,y-1,area,h) + dfs(x,y+1,area,h);
    }

    public int[] solution(int m, int n, int[][] picture) {
        int num = 0;
        int max = -1;
        int i,j;
        Helper h = new Helper();

        h.visited = new boolean[m][n];
        h.picture = picture;
        h.m = m;
        h.n = n;

        for(i = 0; i < m; i++){
            for(j = 0; j < n; j++){
                if(!h.visited[i][j] && picture[i][j] != 0){
                    max = Math.max(dfs(i,j,picture[i][j],h),max);
                    num++;
                }
            }
        }

        int[] ans = new int[2];
        ans[0] = num;
        ans[1] = max;
        return ans;
    }
}
