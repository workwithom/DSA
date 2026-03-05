import java.util.*;


public class DistMatrix {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[][] matrix = new int[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                matrix[i][j] = sc.nextInt();
            }
        }

      
        distancematrixbfs(matrix);
    
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                System.out.print(matrix[i][j] + " ");
            }
            System.out.println();
        }
    }

    public static void distancematrixbfs(int[][] matrix){
        boolean[][] vis = new boolean[matrix.length][matrix[0].length];
        Queue<int[]> q = new LinkedList<>();    
        
        
        for(int i = 0; i < matrix.length; i++){
            for(int j = 0; j < matrix[0].length; j++){
                if(matrix[i][j] == 0){
                    q.add(new int[]{i,j});
                    
                }
            }
        }
        int[][] dir = {{-1,0},{0,-1},{1,0},{0,1}}; 
        while(!q.isEmpty()){
            
            int size = q.size();
            for(int i = 0; i < size; i++){
                int[] curr = q.poll();
                for(int[] e : dir){
                    int r = curr[0] + e[0];
                    int c = curr[1] + e[1];
                    if(r >= 0 && r < matrix.length && c >= 0 && c < matrix[0].length && matrix[r][c] == 1 && !vis[r][c]){
                        matrix[r][c] = matrix[curr[0]][curr[1]] + 1;
                        vis[r][c] = true;
                        q.add(new int[]{r,c});
                    }
                }
            }
        }                                                                       
    }
}

