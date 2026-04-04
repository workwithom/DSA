import java.io.*;

class Result {

    /*
     * Complete the 'timeInWords' function below.
     *
     * The function is expected to return a STRING.
     * The function accepts following parameters:
     *  1. INTEGER h
     *  2. INTEGER m
     */
    public static final String[] ones = {
        "", "one", "two", "three", "four", "five", "six",
        "seven", "eight", "nine", "ten", "eleven", "twelve",
        "thirteen", "fourteen", "fifteen", "sixteen",
        "seventeen", "eighteen", "nineteen"
    };

    public static final String[] tens = {
        "", "", "twenty", "thirty", "forty",
        "fifty", "sixty"
    };
    public static String convert(int num){
        if(num > 0 && num < 20) return ones[num];
        else{
            int temp = num%10;
            num/=10;
            return tens[num] + " " + ones[temp];
        }
    }
    
    
    public static String timeInWords(int h, int m) {
        if( h<1 || h > 12 || m < 0 || m > 60) return "Invalid time"; 
        StringBuilder sb = new StringBuilder();
        String hr = convert(h);
        String min = convert(m);
        if(m == 00){
            sb.append(hr);
            sb.append(" o' clock");
            return sb.toString();
        }else if(m == 30){
            sb.append("half past ");
            sb.append(hr);
        }else if(m == 15) {
            sb.append("quarter past ");
            sb.append(hr);
        }else if( m == 45) {
            sb.append("quarter to ");
            sb.append(convert(h+1));
        }
        
        if(m<30 && m != 15){
            sb.append(min);
            if(m == 1) sb.append(" minute past ");
            else sb.append(" minutes past ");
            sb.append(hr);
        }else if(m>30 && m != 45){
            sb.append(convert(60 - m));
            if(m == 59) sb.append(" minute past ");
            else sb.append(" minutes to ");
            sb.append(convert(h+1));
        }
        return sb.toString();

    }

}

public class TimeInWords {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(System.getenv("OUTPUT_PATH")));

        int h = Integer.parseInt(bufferedReader.readLine().trim());

        int m = Integer.parseInt(bufferedReader.readLine().trim());

        String result = Result.timeInWords(h, m);

        bufferedWriter.write(result);
        bufferedWriter.newLine();

        bufferedReader.close();
        bufferedWriter.close();
    }
}
