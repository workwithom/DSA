public class Stringidentical {
    public static void main(String[] args) {
        String a = "abcd" ;
        String b = "cdab" ;
        String ans = "";
        int n = a.length();
        if(a.length() != b.length()){
            System.out.println("false");
            return;
        }  
        for(int i = 0 ; i < n ; i++ ){
           if (b.charAt(i) == a.charAt(0)){
            String s1 = b.substring(i,n);
            String s2 = b.substring(0,i);

            ans = s1+s2;
            break;
           }
        }
        if(ans.equals(a)){
            System.out.println("true");
        }else{
            System.out.println("false");
        }
    }
}
