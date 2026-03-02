import java.util.LinkedList;
import java.util.Queue;

public class RottingOranges {
    public void main(String[] args) {
        Solution s = new Solution();
        int[][] grid = {{2,1,1},{1,1,0},{0,1,1}};
        System.out.println(s.orangesRotting(grid));
    }
/* 
my observation :

1.  use boolean rotted , for strictly simulate each minute level.
2.  0 - 1 BFS  , if  minutes is 0 , 1 to rot. use dequeue.
3.  Dijkstra algo , if minutes is different for every rot . weighted graph. use priority queue.
*/
    class Solution {
    public int orangesRotting(int[][] grid) {
        int m = grid.length;
        int n = grid[0].length;
        
        Queue<int[]> q = new LinkedList();
        
        int minutes = 0;
        int fresh = 0 ;

        for(int i = 0 ; i < m ; i++ ){
            for (int j = 0 ; j < n ; j++){
                if(grid[i][j]==2) {
                    q.add(new int[]{i,j});
                }
                if(grid[i][j]==1){
                    fresh++;
                }
            }
        }
        if(fresh == 0) return 0;

        int[][] dir = {{-1,0},{0,-1},{1,0},{0,1}};

        while(!q.isEmpty()){
            int s = q.size();
            boolean rotted = false;
            
            for(int i = 0 ; i < s ; i++){
                int[] cur = q.remove();
                for (int[] e : dir){
                    int nr = cur[0]+e[0];
                    int nc = cur[1]+e[1];
                    if(nr<0 || nc<0 || nr >= m || nc >= n) continue;

                    if(grid[nr][nc] == 1 ){
                        grid[nr][nc] = 2;
                        q.add(new int[]{nr, nc});
                        fresh--;
                        rotted = true;
                    }
                }
            }
            if(rotted) minutes++;
        }
        if(fresh>0) return -1;
        return minutes;
        
    }
}
}
