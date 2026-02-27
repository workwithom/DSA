import java.util.Stack;
public class reverseStack {
    public static void main(String[] args) {
        Stack<Integer> s = new Stack<>();
        s.push(4);
        s.push(1);
        s.push(3);
        s.push(2);
        reverseStack(s);
        System.out.println(s);
    }

    public static void reverseStack(Stack<Integer> s) {
        if (s.isEmpty()) return;
        int i = s.pop();
        reverseStack(s);
        insert(s, i);
    }

    public static void insert(Stack<Integer> s, int i) {
        if (s.isEmpty() ) {
            s.push(i);
            return;
        }
        int temp = s.pop();
        insert(s, i);
        s.push(temp);
    }
}
