
import java.util.Scanner;

public class Handmaid {
    public static void main(String[] args){
        Solution s = new Solution();
        Scanner sc = new Scanner(System.in);
        String n = sc.nextLine();
        System.out.println(s.handmaid(n));
    }

    public  static class Solution{
        public String handmaid(String n){
            n = n.toLowerCase();
            String ans = "Of";
            return ans+n;
        }
    }
}
