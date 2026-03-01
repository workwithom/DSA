
    

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
public class GreedyDraft {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        List <List<Integer>> in = new ArrayList<>();
        for(int i = 0 ; i < n ;i++){
            int l = sc.nextInt();
            
            List<Integer> list = new ArrayList<>();
            for (int j =0 ; j < l ;j++){ 
                list.add(sc.nextInt());
            }
                in.add(list);
        }
        
        boolean[] picked = new boolean[m];

        for(int i = 0 ; i < n ;i++){
            int wish = 0 ;
            for(int j = 0 ; j < in.get(i).size();j++){
                if(wish == 0 && !picked[in.get(i).get(j)-1] ){
                    picked[in.get(i).get(j)-1] = true;
                    System.out.println(in.get(i).get(j));
                    wish = 1;
                }
            }
            if(wish == 0){
                System.out.println(0);
            }
        }
        

    }
    
       

}