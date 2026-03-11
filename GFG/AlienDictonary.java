import java.util.*;

public class AlienDictonary {
    
     static int[] topoSort(int V , List<List<Integer>> adj){
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
            if(index != V){
                return new int[0];   
            }
            return topo;
        }
    public static String findOrder(String[] words) {
       
        Set<Character> vertex = new HashSet<>();
        List<List<Integer>> adj = new ArrayList<>();
        for(int i = 0 ; i < 26 ; i++ ){
            adj.add(new ArrayList<>());
        }
        for(String word : words){
            for(char c : word.toCharArray()){
                vertex.add(c);
            }
        }
        
        for(int i = 0 ; i < words.length-1 ; i++){
            String s1 = words[i];
            String s2 = words[i+1];
            if(s1.length() > s2.length() && s1.startsWith(s2)){
                return "";
            }

            int len = Math.min(s1.length(),s2.length());
            for(int ptr = 0 ; ptr < len ; ptr++ ){
                vertex.add(s1.charAt(ptr));
                vertex.add(s2.charAt(ptr));
                if(s1.charAt(ptr) != s2.charAt(ptr)) {
                    adj.get(s1.charAt(ptr) - 'a').add(s2.charAt(ptr) - 'a');
                    break;
                }
            }
        }
        
        int[] topo = topoSort(26,adj);
        String ans = "";

        for(int node : topo){
            char c = (char)('a' + node);
            if(vertex.contains(c)){
                ans += c;
            }
        }
        return ans;
    }
    
    public static void main(String[] args) {
        
        System.out.println(findOrder(new String[]{"baa","abcd","abca","cab","cad"}));
    }
}
