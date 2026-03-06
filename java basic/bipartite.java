import java.util.*;

class Graph {
    int V;
    List<List<Integer>> adj = new ArrayList<>();

    public Graph(int v) {
        V = v;
        adj = new ArrayList<>(v);
        for (int i = 0; i < v; i++) {
            adj.add(new ArrayList<>());
        }
    }

    void addEdge(int u, int v) {
        adj.get(u).add(v);  
        adj.get(v).add(u);  
    }

    
    void printGraph() {
        for (int i = 0; i < V; i++) {
            System.out.print(i + ": ");
            for (int val : adj.get(i))
                System.out.print(val + " ");
            System.out.println();
        }
    }

}
public class bipartite {
    public static void main(String[] args) {

        Graph g = new Graph(5);
        g.addEdge(0, 1);
        g.addEdge(1, 2);
        g.addEdge(2,3);
        g.addEdge(1,4);
        g.addEdge(3, 4);


        bipartite s = new bipartite();
        System.out.print(s.isBipartite(g));
    }



    public boolean dfs(int src, int[] color, List<List<Integer>> adj) {

        for(int neighbor : adj.get(src)) {
            if(color[neighbor] == -1) {
                color[neighbor] = 1 - color[src];
                if(!dfs(neighbor, color, adj))
                    return false;
            }
            else if(color[neighbor] == color[src]) {
                return false;
            }
        }
        return true;
}
    
    public boolean isBipartite(Graph graph) {
        int n = graph.V;
        int[] color = new int[n];
        Arrays.fill(color,-1);

        for(int i = 0; i < n; i++) {
            if(color[i] == -1) {
                color[i] = 0;
                if(!dfs(i, color, graph.adj))
                    return false;
            }   
        }

    return true;

    }   
}  