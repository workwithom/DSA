import java.io.*;
import java.util.*;

class Result {

    /*
     * Complete the 'gridSearch' function below.
     *
     * The function is expected to return a STRING.
     * The function accepts following parameters:
     *  1. STRING_ARRAY G
     *  2. STRING_ARRAY P
     */

    public static String gridSearch(List<String> G, List<String> P) {
        int R = G.size();
        int C = G.get(0).length();
        int r = P.size();
        int c = P.get(0).length();
        
        for(int i = 0; i <= R - r; i++) {
            for(int j = 0; j <= C - c; j++) {
                boolean valid = true;
                if(G.get(i).charAt(j) == (P.get(0).charAt(0))){
                    int n = 0 ;
                    for(int k = i ; k < i + r && k < R ; k++ , n++){
                        int m = 0;
                        for(int l = j ; l < j + c && l < C ; l++ , m++){
                            if( n<r && m<c && G.get(k).charAt(l) == (P.get(n).charAt(m))) {
                                valid = true;
                                
                            } 
                            else {
                                valid = false;
                                break;
                            } 
                        }
                        if (!valid) break;  
                    }
                    if(valid && n==r) return "YES";
                }
            }
        }
        return "NO";
    }

}

public class gridSearch {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int t = Integer.parseInt(bufferedReader.readLine().trim());

for (int tItr = 0; tItr < t; tItr++) {

    String[] firstInput = bufferedReader.readLine().trim().split(" ");
    int R = Integer.parseInt(firstInput[0]);
    int C = Integer.parseInt(firstInput[1]);

    List<String> G = new ArrayList<>();
    for (int i = 0; i < R; i++) {
        G.add(bufferedReader.readLine());
    }

    String[] secondInput = bufferedReader.readLine().trim().split(" ");
    int r = Integer.parseInt(secondInput[0]);
    int c = Integer.parseInt(secondInput[1]);

    List<String> P = new ArrayList<>();
    for (int i = 0; i < r; i++) {
        P.add(bufferedReader.readLine());
    }

    String result = Result.gridSearch(G, P);
    bufferedWriter.write(result);
    bufferedWriter.newLine();
}
            
        bufferedReader.close();
        bufferedWriter.close();
    }
}
