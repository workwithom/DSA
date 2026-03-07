import java.util.*;
class chmin {
  public static void main (String[] args){
    Scanner sc = new Scanner(System.in);
    int n = sc.nextInt();
    int x = sc.nextInt();
    List<Integer> l = new ArrayList<>(n);
    for(int i = 0 ; i < n ; i++){
      l.add(sc.nextInt());
    }
    for(int i = 0 ; i < n ; i++){
      if(l.get(i) < x ){
        x = l.get(i);
        System.out.println(1);
      }else System.out.println(0);
    }
  }
}
