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
public class DetectCycle {
    public static void main(String[] args) {
        Graph g = new Graph(5);
        g.addEdge(1, 3);
        g.addEdge(1, 4);
        g.addEdge(4, 2);
        g.addEdge(0, 1);
        
        g.printGraph();
        System.out.println(hasCycle(g));
    }

    static boolean hasCycle(Graph g) {
        int V = g.V;
        boolean[] vis = new boolean[V];
        
        List<List<Integer>> adjList = new ArrayList<>(V);
        for(int i = 0 ; i < V ; i++){
            adjList.add(new ArrayList<>());
        }

        for (int i = 0; i < V; i++) {
            for (int j = 0; j < g.adj.get(i).size(); j++) {
                adjList.get(i).add(g.adj.get(i).get(j));
            }
        }

        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                if (dfs(i, -1, vis, adjList)) {
                    return true;
                }
            }
        }



        return false;
    }

    static boolean dfs(int src, int parent, boolean[] vis, List<List<Integer>> adjList) {
        vis[src] = true;

        for (int i = 0; i < adjList.get(src).size(); i++) {
            if (!vis[adjList.get(src).get(i)]) {
                if (dfs(adjList.get(src).get(i), src, vis, adjList)) {
                    return true;
                }
            } else if (adjList.get(src).get(i) != parent) {
                return true;
            }
        }
        return false;
    }

    
}