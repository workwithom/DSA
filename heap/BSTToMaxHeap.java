
import java.util.ArrayList;
class Node {
    int data;
    Node left, right;
    Node(int item) {
        data = item;
        left = right = null;
    }
}

public class BSTToMaxHeap {
    static ArrayList<Integer> values = new ArrayList<>();
    int index = 0;
    public static void convertToMaxHeapUtil(Node root) {
        if (root == null) return;
        inorderTraversal(root);
        BSTToMaxHeap tree = new BSTToMaxHeap();
        tree.postorder(root);
        
         
    }
    public static void inorderTraversal(Node node) {
            
        if (node == null) return;
        inorderTraversal(node.left);
        values.add(node.data);
        inorderTraversal(node.right);
    }

    public void postorder(Node node){
        if (node == null) return;
        postorder(node.left);
        postorder(node.right);
        node.data = values.get(index++);
    }

    public static void main(String[] args) {
        Node root = new Node(4);
        root.left = new Node(2);
        root.right = new Node(6);
        root.left.left = new Node(1);
        root.left.right = new Node(3);
        root.right.left = new Node(5);
        root.right.right = new Node(7);

        convertToMaxHeapUtil(root);
        
    }
}
