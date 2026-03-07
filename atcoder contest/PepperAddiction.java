import java.util.*;
class PepperAddiction{
    public static void main (String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        List<Integer> p = new ArrayList<>(m+1);
        List<List<Integer>> od = new ArrayList<>(n+1);
        p.add(0);
        for(int i = 1 ; i <= m ; i++){
            p.add(sc.nextInt());
        }
        od.add(new ArrayList<>());
        for(int i = 1 ; i <= n ; i++){

            od.add(new ArrayList<>());
            od.get(i).add(sc.nextInt());
            od.get(i).add(sc.nextInt());

        }
        int collect=0;
        for(int i = 1 ; i <= n ; i++){
            if(od.get(i).get(1)<=p.get(od.get(i).get(0))){
                collect+=od.get(i).get(1);
                 int t = p.get(od.get(i).get(0));
                 t-=od.get(i).get(1);
                 p.set(od.get(i).get(0),t);
            }
            else{
                collect+=p.get(od.get(i).get(0));
                p.set(od.get(i).get(0),0);
            }
        }
        System.out.println(collect);

    }                   
}


