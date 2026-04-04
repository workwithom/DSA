

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
        if(node == null) return true;
        if(node.left == null && node.right == null) return true;
        
        if(node.left != null && node.right != null){
            return checkFullBT(node.left) && checkFullBT(node.right);
        }

        return false;
    }

    static int countNodesDFS(Node node){
        if(node == null) return 0;
        return 1+ countNodesDFS(node.left) + countNodesDFS(node.right);
    }
    
    // static int countNodesBFS(Node node){
        
    // }

    static boolean checkCBT(Node node, int index, int count){
        if(node == null) return true;
        if(index >= count) return false;
        return checkCBT(node.left, 2*index+1 ,count) && checkCBT(node.right, 2*index+2 ,count);
    }

    static void mirrorBT(Node node){
        if( node == null ) return;
        if(node.left != null ){
            mirrorBT(node.left);
        }
        else if(node.right != null){
            mirrorBT(node.right);
        }
        Node temp = node.left;
        node.left = node.right;
        node.right = temp;

    }
    static int LeafSumTracker(Node node , int index ){
        if(node == null) return 0;
        if(node.left == null && node.right == null) return node.data;
        return LeafSumTracker(node.left , 2*index+1) + LeafSumTracker(node.right , 2*index+2);
    }

        public static void main(String[] args) {
        
        createTree tree = new createTree();
        tree.root = new Node(10);
        tree.root.left = new Node(20);
        tree.root.right = new Node(30);
        tree.root.left.left = new Node(40);
        //tree.root.left.right = new Node(50);
        tree.root.right.left = new Node(60);
        tree.root.left.left.left = new Node(70);
        inorder(tree.root);
        System.out.println();
        preorder(tree.root);
        System.out.println();
        postorder(tree.root);
        System.out.println();
        System.out.println(checkFullBT(tree.root));
        int count = countNodesDFS(tree.root);
        System.out.println(checkCBT(tree.root , 0 , count));
        mirrorBT(tree.root);
        


    } 
} 