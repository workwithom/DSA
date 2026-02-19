import java.io.*;
import java.util.*;

class Result {

    /*
     * Complete the 'organizingContainers' function below.
     *
     * The function is expected to return a STRING.
     * The function accepts 2D_INTEGER_ARRAY container as parameter.
     */

    public static String organizingContainers(List<List<Integer>> container) {
        int n = container.size();
        
        int[] rowSum = new int[n];
        int[] colSum = new int[n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                rowSum[i] += container.get(i).get(j);
                colSum[j] += container.get(i).get(j);
            }
        }
        Arrays.sort(rowSum);
        Arrays.sort(colSum);
        for (int i = 0; i < n; i++) {
            if (rowSum[i] != colSum[i]) {
                return "Impossible";
            }
        }
        return "Possible";
        

    }

}

public class organizingContainers {
    public static void main(String[] args) throws IOException {
        List<List<Integer>> container = new ArrayList<List<Integer>>();
        container.add(Arrays.asList(1,4,0,0));
        container.add(Arrays.asList(2,1,2,1));
        container.add(Arrays.asList(0,1,1,3));
        container.add(Arrays.asList(2,0,2,2));
        
        String result = Result.organizingContainers(container);
        System.out.println(result);

    }
}
