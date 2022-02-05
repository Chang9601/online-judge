import java.util.*;

class Solution {    
    
    class Point {
        int x;
        int y;
        
        public Point(int x,int y) {
        	this.x = x;
        	this.y = y;
        }
    }
    
    public int solution(int[][] maps) {
        int r = maps.length;
        int c = maps[0].length;
        int[][] dis = new int[r][c];
        int x,y;
        int nx,ny;
        int[] dx = {-1,1,0,0};
        int[] dy = {0,0,-1,1};
        Queue<Point> q = new LinkedList<>();
        
        for(int[] d : dis) 
            Arrays.fill(d, -1);
        
        dis[0][0] = 0;
        q.add(new Point(0,0));
        
        while(!q.isEmpty()){
            Point p = q.poll();
            x = p.x;
            y = p.y;
            
            for(int i = 0; i < 4; i++){
                nx = x+dx[i];
                ny = y+dy[i];
                
                if(nx >= r || nx < 0 || ny >= c || ny < 0) continue;
                if(dis[nx][ny] != -1 || maps[nx][ny] == 0) continue;
                
                q.add(new Point(nx,ny));
                dis[nx][ny] = dis[x][y]+1;
            }
        }
        
        return dis[r-1][c-1] == -1 ? -1 : dis[r-1][c-1]+1;
    }
}
