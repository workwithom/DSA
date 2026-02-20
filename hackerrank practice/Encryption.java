import java.util.*;

class Result {

    /*
     * Complete the 'encryption' function below.
     *
     * The function is expected to return a STRING.
     * The function accepts STRING s as parameter.
     */

    public static String encryption(String s) {
        
        s = s.replaceAll("\\s", "");
        float L = s.length();
        int m = (int) Math.floor(Math.sqrt(L));
        int n = (int) Math.ceil(Math.sqrt(L));
        if( !(m*n >= L)){
            return "invalid input";
        }
        char[][] matrix = new char[m][n];
        int k = 0 ;
        
        while(k<L){
            int  i = k/n;
            int  j = k%n;
            matrix[i][j] = s.charAt(k);
            k++;        
        }
        
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                sb.append(matrix[j][i]);
            }
            sb.append(" ");
        }
        return sb.toString();
    

    }

}

public class Encryption {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String s = in.nextLine();
        String result = Result.encryption(s);
        System.out.println(result);
    }
}
