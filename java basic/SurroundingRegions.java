public class SurroundingRegions {
    public void dfs(int i , int j ,int m , int n, char[][] board , boolean[][] V){
        
        if(i < 0 || j < 0 || i >= m || j >= n || board[i][j] != 'O' || V[i][j]) return;
        V[i][j] = true;
        dfs(i-1, j,m, n, board, V);
        dfs(i, j-1,m, n, board, V);
        dfs(i+1, j,m, n, board, V);
        dfs(i, j+1,m, n, board, V);
        
    }
    public void solve(char[][] board) {
        int m = board.length;
        int n = board[0].length;
        boolean[][] V = new boolean[m][n];
        
        
        for(int i = 0 ; i < n ; i++){
            int rt = 0 ;
            int rb = m-1 ;
            int c = i ; 
            dfs(rt ,c , m , n , board , V);
            dfs(rb ,c , m , n , board , V);
        }
        for(int i = 0 ; i < m ; i++){
            int r = i ;
            int ct = 0 ;
            int cb = n-1;
            dfs(r ,ct , m , n , board , V);
            dfs(r ,cb , m , n , board , V);
        }
        
        for(int i = 1; i < m-1; i++){
            for(int j = 1; j < n-1; j++){
                if(board[i][j] == 'O' && !V[i][j]) board[i][j] = 'X';
            }
        }
    }

    public static void main(String[] args) {
        char[][] board = {{'X','X','X','X'},{'X','O','O','X'},{'X','X','O','X'},{'X','O','X','X'}};
        SurroundingRegions s = new SurroundingRegions();
        s.solve(board);
        for(int i = 0 ; i < board.length ; i++){
            for(int j = 0 ; j < board[0].length ; j++){
                System.out.print(board[i][j] + " ");
            }
            System.out.println();
        }
    }
}
