import java.util.*;


class Node {
    int data;
    Node left;
    Node right;
    Node(int data) {
        this.data = data;
        left = right = null;
    }
}
    

public class createTree {
    Node root;

    static void inorder(Node root) {
        if (root==null)
            return;
        inorder(root.left);
        System.out.print(root.data +" ");
        inorder(root.right);
    }
    static void preorder(Node root){
        if (root==null)
            return;
        System.out.print(root.data +" ");
        preorder(root.left);
        preorder(root.right);
    }
    static void postorder(Node root){
        if (root==null)
            return;
        postorder(root.left);
        postorder(root.right);
        System.out.print(root.data + " ");
        
    }

    static boolean checkFullBT(Node node){
        if(node == null) return false;
        if(checkFullBT(node.left) && checkFullBT(node.right)) return true;
        else if(!checkFullBT(node.left) && !checkFullBT(node.right)) return true;

        return false;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        createTree tree = new createTree();
        tree.root = new Node(10);
        tree.root.left = new Node(20);
        tree.root.right = new Node(30);
        tree.root.left.left = new Node(40);
        tree.root.left.right = new Node(50);
        tree.root.left.left = null;
        //tree.root.left.right = new Node(80);
        inorder(tree.root);
        System.out.println(checkFullBT(tree.root));


    } 
}