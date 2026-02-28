
import java.util.*;

public class GenerateParentheses {
    public static void main(String[] args) {
        Solution s = new Solution();
        System.out.println(s.generateParenthesis(3));
    }

    public static class Solution {
        public static List<String> generateParenthesis(int n) {
            List<String> res = new ArrayList<String>();
        
            para(n,0,0,"",res);
            return res;
        }

        public static void para(int n,int open,int close,String str,List<String> res){
            if(open==n && close==n){
                res.add(str);
                return;
            }
            if(open<n){
                para(n,open+1,close,str+"(",res);
            }
            if(close<open){
                para(n,open,close+1,str+")",res);
            }

        }
    }

    
}
