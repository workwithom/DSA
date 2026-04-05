import java.io.*;
import java.util.*;
import java.util.stream.*;
import static java.util.stream.Collectors.toList;

class Result {

    /*
     * Complete the 'surfaceArea' function below.
     *
     * The function is expected to return an INTEGER.
     * The function accepts 2D_INTEGER_ARRAY A as parameter.
     */

    public static int surfaceArea(List<List<Integer>> A) {
        int n = A.size();
        int m = A.get(0).size();
        int area = 0;
          
        for(int i  = 0 ; i < n ; i++){
            for(int j = 0 ; j < m  ; j++){
                int a = A.get(i).get(j);
                area+=2;
                int up = (i==0)? 0 : A.get(i-1).get(j);
                int dn = (i==n-1)? 0 : A.get(i+1).get(j);
                int lf = (j==0)? 0 : A.get(i).get(j-1);
                int rt = (j==m-1)? 0 : A.get(i).get(j+1);
                
                area+=Math.max(a-up , 0);
                area+=Math.max(a-dn , 0);
                area+=Math.max(a-lf , 0);
                area+=Math.max(a-rt , 0);                
            }
        }
        return area;
    }

}

public class SurfaceArea {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        String[] firstMultipleInput = bufferedReader.readLine().replaceAll("\\s+$", "").split(" ");

        int H = Integer.parseInt(firstMultipleInput[0]);

        int W = Integer.parseInt(firstMultipleInput[1]);

        List<List<Integer>> A = new ArrayList<>();

        IntStream.range(0, H).forEach(i -> {
            try {
                A.add(
                    Stream.of(bufferedReader.readLine().replaceAll("\\s+$", "").split(" "))
                        .map(Integer::parseInt)
                        .collect(toList())
                );
            } catch (IOException ex) {
                throw new RuntimeException(ex);
            }
        });

        int result = Result.surfaceArea(A);

        bufferedWriter.write(String.valueOf(result));
        bufferedWriter.newLine();

        bufferedReader.close();
        bufferedWriter.close();
    }
}
