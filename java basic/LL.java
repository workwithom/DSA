public class LL {
    Node head;

    class Node{
        String data;
        Node next;
        

        Node(String data){
            this.data = data;
            this.next = null;
        }
    }
    
    // addFirst
    public void addFirst(String data){
        
        Node newNode = new Node(data);
        if(head == null){
            head = newNode;
            return;
        }
        newNode.next = head;
        head = newNode;
    }
    // addLast
    public void addLast(String data) {
        Node newNode = new Node(data);
        if(head == null){
            head = newNode;
            return;
        }
        Node currNode = head;
        while(currNode.next != null){
            currNode = currNode.next;
        }
        currNode.next = newNode;

    }
    // printList
    public static void printList(LL list){
        Node currNode = list.head;
        while(currNode != null){
            System.out.print(currNode.data + " -> ");
            currNode = currNode.next;
        }
        System.out.println("null");
    }
    //reverseIterate
    public void reverseIterate(){
        Node prevNode = null;
        Node currNode = head;
        Node nextNode;

        while(currNode != null){
            nextNode = currNode.next;
            currNode.next = prevNode;
            prevNode = currNode;
            currNode = nextNode;
        }
        head = prevNode;
    }
    //reverseRecursive
    public Node reverseRecursive(Node head){
        if(head == null || head.next == null){
            return head;
        }
        Node newHead = reverseRecursive(head.next);
        head.next.next = head; 
        head.next = null;
        this.head = newHead;
        return newHead;

    
    }


    // delete nth node from end
    public void deleteNthFromEnd(int n){
        int size = 0;
        Node currNode = head;
        while(currNode != null){
            currNode = currNode.next;
            size++;
        }
        if(n == size){
            head = head.next;
            return;
        }
        int i = 1;
        int toFind = size - n;
        Node prevNode = head;
        while(i < toFind){
            prevNode = prevNode.next;
            i++;
        }
        prevNode.next = prevNode.next.next;
    }

    
    

    public static void main(String[] args) {
        LL list = new LL();
        list.addFirst("a");
        list.addFirst("is");
        list.addLast("list");
        list.addLast("linked");
        list.addFirst("this");
        printList(list);
        list.reverseRecursive(list.head);
        printList(list);
    }

}


