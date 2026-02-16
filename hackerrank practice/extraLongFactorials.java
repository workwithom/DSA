import java.io.*;
import java.math.BigInteger;

class Result {

    public static void extraLongFactorials(int n) {

        BigInteger result = BigInteger.ONE;

        for (int i = 2; i <= n; i++) {
            result = result.multiply(BigInteger.valueOf(i));
        }

        System.out.println(result);
    }
}

public class extraLongFactorials {
    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine().trim());

        Result.extraLongFactorials(n);
        br.close();
    }
}
