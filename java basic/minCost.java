import java.util.*;

public class minCost {

    public static long minCost(int[] basket1, int[] basket2) {
        Map<Integer,Integer> map = new HashMap<>();
        int globalMin = Integer.MAX_VALUE;

        for(int x : basket1){
            map.put(x,map.getOrDefault(x,0)+1);
            globalMin = Math.min(globalMin,x);
        }
        for(int x : basket2){
            map.put(x,map.getOrDefault(x,0)-1);
            globalMin = Math.min(globalMin,x);
        }

        List<Integer> swap = new ArrayList<>();
        for(int key : map.keySet()){
            int diff = map.get(key);
            if(diff % 2 != 0) return -1;
            for(int i=0;i<Math.abs(diff)/2;i++)
                swap.add(key);
        }
        Collections.sort(swap);
        long cost = 0;
        for(int i=0;i<swap.size()/2;i++){
            cost += Math.min(swap.get(i),2*globalMin);
        }
        return cost;

    }
    public static void main(String[] args) {

        int[] basket1 = {4,2,2,2};
        int[] basket2 = {1,4,1,2};
        System.out.println("The minimum cost is: " + minCost( basket1, basket2));

    }
}