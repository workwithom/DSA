import java.util.*;

public class java {

    public static long solve(long[] A , int n ) {
        int i = 0;
        int j = 0;
        long maxSum = Integer.MIN_VALUE;
        long sum = 0;
        while(i < n && j < n){
            sum+=A[j];
            
            if(sum > maxSum) {maxSum = sum; j++;}
            
            else {
                if(i<j && A[i]<0) {
                    sum-=A[i];
                    i++;
                    
                }
                j++;
            } 


        }
        return maxSum;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        long[] A = new long[n];
        for(int i = 0 ; i < n ; i++){
            A[i] = sc.nextInt();
        }
        long ans =solve(A,n);
        System.out.println(ans);
        sc.close();
    }
}
