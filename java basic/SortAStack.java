import java.util.*;  
public class SortAStack {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Stack<Integer> s = new Stack<>();
        // integers input in a line seperated by space 
        String[] str = sc.nextLine().split(" ");
        for(String st : str){
            s.addElement(Integer.parseInt(st));
        } 
        sortstack(s);
        System.out.println(s);  
    }


    public static void sortstack(Stack<Integer> s) {
        if(s.isEmpty()) return;
        int i = s.pop();
        sortstack(s);
        insert(s,i);
    }

    public static void insert(Stack<Integer> s,int i){
        if(s.isEmpty() || s.peek() < i){
            s.push(i);
            return;
        }
        int temp = s.pop();
        insert(s,i);
        s.push(temp);
    }
    
}
