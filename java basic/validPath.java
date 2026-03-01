import java.util.*;

public class validPath {
    public static void main(String[] args) {
        Solution s = new Solution();
        System.out.println(s.validPath(3, new int[][]{{0,1},{1,2},{2,0}}, 0, 2));  
    }


        public static class Solution {
            public static boolean validPath(int n, int[][] edges, int source, int destination) {
                List<List<Integer>> adjList = new ArrayList<List<Integer>>(n);
                for(int i = 0; i < n; i++){
                    adjList.add(new ArrayList<>());
                }
                for(int i = 0 ; i < edges.length ; i++){
                    adjList.get(edges[i][0]).add(edges[i][1]); 
                    adjList.get(edges[i][1]).add(edges[i][0]); 
                }

                boolean[] visited = new boolean[n];
                Queue<Integer> q = new LinkedList<>();  
                q.add(source);
                visited[source] = true;
                
                while(!q.isEmpty()){

                    int curr = q.remove();
                    if(curr == destination) return true;
                    
                    for(int i = 0 ; i < adjList.get(curr).size();i++){
                        if(!visited[adjList.get(curr).get(i)]){
                            visited[adjList.get(curr).get(i)] = true;
                            q.add(adjList.get(curr).get(i));
                        }
                    }

                }
                return false;

            }
        }
}
