import java.util.*;
class ShortestPathDAG {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int V = sc.nextInt();
        int E = sc.nextInt();
        int[][] edges = new int[E][3];
        for(int i = 0 ; i < E ; i++ ){
            for(int j = 0 ; j < 3 ; j++ ){
                edges[i][j] = sc.nextInt();
            }
        }
        Solution obj = new Solution();
        int[] ans = obj.shortestPath(V, E, edges);
        for(int i = 0 ; i < V ; i++ ){
            System.out.print(ans[i] + " ");
        }
    }
}
class Solution {
    
    class Pair {
        int node;
        int weight;
        
        Pair(int node , int weight){
            this.node = node;
            this.weight = weight;
        }
    }
    
    void topoSort(Stack<Integer> st , boolean[] vis , int node , List<List<Pair>> adj ) {
        vis[node] = true;
        for(Pair P : adj.get(node)){
            if(!vis[P.node]){
                topoSort(st,vis,P.node,adj);
            }
        }
        st.push(node);
    }
    
    public int[] shortestPath(int V, int E, int[][] edges) {
        List<List<Pair>> adj = new ArrayList<>();
        
        for(int i = 0 ; i < V ; i++ ) {
            adj.add(new ArrayList<>());
        }
        
        for(int i = 0 ; i < E ; i++ ){
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];

            adj.get(u).add(new Pair(v, wt));
        }
        
        boolean[] vis = new boolean[V];
        Stack<Integer> st = new Stack<>();
        
        for(int i = 0 ; i < V ; i++) {
            if(!vis[i]){
                topoSort(st,vis,i,adj);
            }
        }
        
        int[] dist = new int[V];
        Arrays.fill(dist,Integer.MAX_VALUE);
        
        dist[0] = 0;
        while(!st.isEmpty()){
            int node = st.pop();
            
            if(dist[node] != Integer.MAX_VALUE){
                for(Pair p : adj.get(node)){
                    int v = p.node;
                    int wt = p.weight;
                    
                    if(dist[node] + wt < dist[v]){
                        dist[v] = dist[node] + wt;
                    }
                }
            }
        }
        
        for(int i = 0 ; i < V ; i++ ) {
            if(dist[i] == Integer.MAX_VALUE){
                dist[i] = -1;
            }
        }
        return dist;
    }
}