import java.util.*;



class Solution {

    public static int formingMagicSquare(List<List<Integer>> arr1,int[][][] arr2) {
        
        int minCost = Integer.MAX_VALUE;
        for (int k = 0; k < 8; k++) {
            int cost = 0;

            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    cost += Math.abs(arr1.get(i).get(j) - arr2[k][i][j]);
                }
            }

            minCost = Math.min(minCost, cost);
        }

        return minCost;
    }
}



public class MagicSquare {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        List<List<Integer>> s = new ArrayList<>();
        int[][][] magic = {
        {{8,1,6},{3,5,7},{4,9,2}},
        {{6,1,8},{7,5,3},{2,9,4}},
        {{4,9,2},{3,5,7},{8,1,6}},
        {{2,9,4},{7,5,3},{6,1,8}},
        {{8,3,4},{1,5,9},{6,7,2}},
        {{4,3,8},{9,5,1},{2,7,6}},
        {{6,7,2},{1,5,9},{8,3,4}},
        {{2,7,6},{9,5,1},{4,3,8}}
    };
        
        for (int i = 0; i < 3; i++) {
            s.add(new ArrayList<>());
            for (int j = 0; j < 3; j++) {
                s.get(i).add(sc.nextInt());
            }
        }
        System.out.println(Solution.formingMagicSquare(s,magic));
       
    }
    
}
