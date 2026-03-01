public class numberOfProvinces {
    public void main(String[] args) {
        Solution s = new Solution();
        int[][] isConnected = {{1,1,0},{1,1,0},{0,0,1}};
        System.out.println(s.findCircleNum(isConnected));
    }

    public class Solution {
        public void dfs(int[][] arr , int node , int[] visited ){
        if(node < 0 || node > arr.length ) return;
        
        visited[node] = 1;
        for(int i = 0 ; i < arr.length ; i++ ){
            if (arr[node][i] == 1 && visited[i] == 0){
                dfs(arr , i , visited);
            }
        }
        
    }
    public int findCircleNum(int[][] isConnected) {
        int nop = 0 ;
        int n = isConnected.length;
        int m = isConnected[0].length;
        int[] visited = new int[n+1];
        for(int i = 0 ; i < isConnected.length ; i++){
                if( visited[i] == 0 ){
                    nop++;
                    dfs(isConnected , i , visited);
                }
        }
        
        return nop;
    }
    }   
}
