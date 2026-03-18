import java.util.*;

class Pair{
    int distance;
    int node;
    
    Pair(int n , int d ){
        this.node = n ;
        this.distance = d;
        
    }
}

public class DijkstrasAlgo {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int V = sc.nextInt();
        int E = sc.nextInt();
        int src = sc.nextInt();
        int[][] edges = new int[E][3];
        for(int i = 0 ; i < E ; i++ ){
            for(int j = 0 ; j < 3 ; j++ ){
                edges[i][j] = sc.nextInt();
            }
        }

        Solution obj = new Solution();
        int[] ans = obj.dijkstra(V, edges, src);
        for(int i = 0 ; i < V ; i++ ){
            System.out.print(ans[i] + " ");
        }
    }
    static class Solution {
        public static int[] dijkstra(int V, int[][] edges, int src) {
            List<List<Pair>> adj = new ArrayList<>(V);
            for(int i = 0 ; i < V ; i++ ) adj.add(new ArrayList<>());
            for(int i = 0 ; i < edges.length ; i++ ){
                adj.get(edges[i][0]).add(new Pair(edges[i][1],edges[i][2]));
                adj.get(edges[i][1]).add(new Pair(edges[i][0],edges[i][2]));
            }
            PriorityQueue<Pair> pq = new PriorityQueue<>((x,y)-> x.distance - y.distance);
            int[] dist = new int[V];
            Arrays.fill(dist,Integer.MAX_VALUE);
            dist[src] = 0 ;
            pq.add(new Pair(src,0));
            
            while(pq.size() != 0 ){
                Pair cur = pq.poll();
                int dis = cur.distance;
                int node = cur.node;
                if(dis > dist[node]) continue;
                
                for(int i = 0 ; i < adj.get(node).size(); i++){
                    Pair np = adj.get(node).get(i);
                    int ew = np.distance;
                    int an = np.node;
                    
                    if(dis + ew < dist[an]){
                        dist[an] = dis + ew;
                        pq.add(new Pair(an, dist[an]));
                    }
                }
            } 
            return dist;
        }
    }
}