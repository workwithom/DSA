public class rotate_String {
    public static void main(String[] args) {
        String s = "abcde";
        String goal = "cdeab";
    String temp = new String (goal + goal);
    if (temp.contains(s)){
        System.out.println("true");
    }
}
}
