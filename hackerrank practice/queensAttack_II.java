import java.io.*;
import java.util.*;
import java.util.stream.*;
import static java.util.stream.Collectors.toList;

class Result {

    /*
     * Complete the 'queensAttack' function below.
     *
     * The function is expected to return an INTEGER.
     * The function accepts following parameters:
     *  1. INTEGER n
     *  2. INTEGER k
     *  3. INTEGER r_q
     *  4. INTEGER c_q
     *  5. 2D_INTEGER_ARRAY obstacles
     */

    public static int queensAttack(int n, int k, int r_q, int c_q, List<List<Integer>> obstacles) {
        
        int up = n - r_q;
        int down = r_q -1;
        int right = n - c_q;
        int left = c_q - 1 ;
        int upright= Math.min( up , right) ;
        int upleft = Math.min(up,left);
        int downright= Math.min(down,right);
        int downleft= Math.min(down,left);
        
        for(List<Integer> obs : obstacles ){
            int r = obs.get(0);
            int c = obs.get(1);
            
            if(c==c_q){
                if(r>r_q) up = Math.min(up,r-r_q-1);
                else down = Math.min(down , r_q - r -1);
            }
            
            if(r==r_q){
                if(c>c_q) right = Math.min(right,c-c_q-1);
                else left = Math.min(left , c_q - c -1);
            }
            
            if( Math.abs(r - r_q) == Math.abs(c - c_q)){
                if(r>r_q && c>c_q) upright= Math.min(upright,r-r_q-1);
                
                else if(r>r_q && c<c_q) upleft = Math.min(upleft,r-r_q-1);
                
                else if ( r<r_q && c>c_q ) downright = Math.min(downright,r_q-r-1);
                
                else downleft = Math.min(downleft,r_q-r-1);
            }
        }
        return up+down+right+left+upright+upleft+downright+downleft;
        
    }

}

public class queensAttack_II {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        String outputPath = System.getenv("OUTPUT_PATH");
BufferedWriter bufferedWriter;
if (outputPath != null) {
    try {
        bufferedWriter = new BufferedWriter(new FileWriter(outputPath));
    } catch (IOException e) {
        // Handle the exception
        System.err.println("Error writing to file: " + e.getMessage());
        return;
    }
} else {
    // Output to console if the environment variable is not set
    bufferedWriter = new BufferedWriter(new OutputStreamWriter(System.out));
}
        String[] firstMultipleInput = bufferedReader.readLine().replaceAll("\\s+$", "").split(" ");

        int n = Integer.parseInt(firstMultipleInput[0]);

        int k = Integer.parseInt(firstMultipleInput[1]);

        String[] secondMultipleInput = bufferedReader.readLine().replaceAll("\\s+$", "").split(" ");

        int r_q = Integer.parseInt(secondMultipleInput[0]);

        int c_q = Integer.parseInt(secondMultipleInput[1]);

        List<List<Integer>> obstacles = new ArrayList<>();

        IntStream.range(0, k).forEach(i -> {
            try {
                obstacles.add(
                    Stream.of(bufferedReader.readLine().replaceAll("\\s+$", "").split(" "))
                        .map(Integer::parseInt)
                        .collect(toList())
                );
            } catch (IOException ex) {
                throw new RuntimeException(ex);
            }
        });

        int result = Result.queensAttack(n, k, r_q, c_q, obstacles);

        bufferedWriter.write(String.valueOf(result));
        bufferedWriter.newLine();

        bufferedReader.close();
        bufferedWriter.close();
    }
}
