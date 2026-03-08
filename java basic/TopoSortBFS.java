import java.util.*;
public class TopoSortBFS {
    static class Graph{
        int V;
        List<List<Integer>> adj = new ArrayList<>();
        public Graph(int v) {
            V = v;
            adj = new ArrayList<>(v);
            for (int i = 0; i < v; i++) {
                adj.add(new ArrayList<>());
            }
        }

        void addEdge(int u, int v){
            adj.get(u).add(v);              //directed graph
        }

        void printGraph(){
            for (int i = 0; i < V; i++) {
                System.out.print(i + ": ");
                for (int val : adj.get(i))
                    System.out.print(val + " ");
                System.out.println();
            }
        }

        int[] topoSort(){
            int[] indegree = new int[V];
            for (int i = 0; i < V; i++) {
                for (int j = 0; j < adj.get(i).size(); j++) {
                    indegree[adj.get(i).get(j)]++;
                }
            }
            Queue<Integer> q = new LinkedList<>();
            for (int i = 0; i < V; i++) {
                if(indegree[i] == 0){
                    q.add(i);
                }
            }
            int[] topo = new int[V];
            int index = 0;
            while(!q.isEmpty()){
                int curr = q.poll();
                topo[index++] = curr;
                for (int i = 0; i < adj.get(curr).size(); i++) {
                    indegree[adj.get(curr).get(i)]--;
                    if(indegree[adj.get(curr).get(i)] == 0){
                        q.add(adj.get(curr).get(i));
                    }
                }
            }
            return topo;
        }    
    }
    public static void main(String[] args) {
        Graph g = new Graph(6); 
        g.addEdge(5, 2);
        g.addEdge(5, 0);
        g.addEdge(4, 0);
        g.addEdge(4, 1);
        g.addEdge(2, 3);
        g.addEdge(3, 1);
        g.printGraph();
        int[] topo = g.topoSort();
        for (int i = 0; i < topo.length; i++) {
            System.out.print(topo[i] + " ");
        }

    }
}
