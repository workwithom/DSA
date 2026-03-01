import java.util.*;

public class find_the_path_in_matrix {

    public static void main(String[] args) {
        int[][] matrix = {{0,1,0},{0,0,0},{1,0,0}};
        System.out.println(shortestPath(matrix));
    }

    public static int shortestPath(int[][] matrix) {

        int n = matrix.length;
        int m = matrix[0].length;

        if(matrix[0][0] == 1) return -1;

        boolean[][] visited = new boolean[n][m];
        Queue<int[]> q = new LinkedList<>();

        q.add(new int[]{0,0});
        visited[0][0] = true;
        int steps = 0;

        int[][] dir = {
            {1,0},   
            {-1,0},  
            {0,1},   
            {0,-1}   
        };

        while(!q.isEmpty()) {
            int size = q.size();
            for(int i = 0; i < size; i++) {
                int[] curr = q.poll();
                int r = curr[0];
                int c = curr[1];

                if(r == n-1 && c == m-1)
                    return steps;

                for(int[] d : dir) {
                    int nr = r + d[0];
                    int nc = c + d[1];
                    if(nr >= 0 && nc >= 0 && nr < n && nc < m && !visited[nr][nc] && matrix[nr][nc] == 0) {
                        visited[nr][nc] = true;
                        q.add(new int[]{nr, nc});
                    }
                }
            }
            steps++;
        }
        return -1;
    }
}