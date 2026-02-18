import java.io.*;
import java.util.*;
import java.util.stream.*;
import static java.util.stream.Collectors.toList;

class Result {

    /*
     * Complete the 'nonDivisibleSubset' function below.
     *
     * The function is expected to return an INTEGER.
     * The function accepts following parameters:
     *  1. INTEGER k
     *  2. INTEGER_ARRAY s
     */

    public static int nonDivisibleSubset(int k, List<Integer> s) {
        int[] freq = new int[k];
        for(int num : s){
            freq[num%k]++;
        }
        int count = 0;
        if(freq[0]>0){
            count++;
        }
        for(int i = 1; i <= k/2; i++){
            if(i!=k-i){
                count +=Math.max(freq[i],freq[k-i]);
            } else {
                if(freq[i]>0){
                    count++;
                }
            }
        }
        return count;

    }

}

public class nonDivisibleSubset {
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

        List<Integer> s = Stream.of(bufferedReader.readLine().replaceAll("\\s+$", "").split(" "))
            .map(Integer::parseInt)
            .collect(toList());

        int result = Result.nonDivisibleSubset(k, s);

        bufferedWriter.write(String.valueOf(result));
        bufferedWriter.newLine();

        bufferedReader.close();
        bufferedWriter.close();
    }
}
