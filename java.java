import java.util.Scanner;
public class java {
    public static void main(String[] args) {
        // String car = "volvo";
        // System.out.println(car.toUpperCase());
        // System.out.println("Hello, World!");

        // int a = 23; 
        // int b = 45;
        // int sum = a + b;
       // System.out.println("The sum of a and b is: " + sum);

        //int ans = (a*b) / (a-b);
       // System.out.println("The answer is: " + ans);

        // Scanner sc = new Scanner(System.in);
        // String name = sc.nextLine();
        // System.out.println("You entered: " + name);
        // int a = sc.nextInt();
        // int b = sc.nextInt();
        // System.out.println("The sum of a and b is: " + (a+b));

        // Scanner sc = new Scanner(System.in);
        // int age = sc.nextInt();
        // if ( age > 18 ){
        //     System.out.println("You can drive");
        // }else{
        //     System.out.println("You cannot drive");
        // }

        // for (int i = 0 ; i < 5; i++){
        //     System.out.println(age);
        // }


        //reverse a number
        {
        Scanner sc = new Scanner(System.in);
        int x = sc.nextInt();
        int rev = 0;
        while (x != 0){
            int digit = x % 10;
            rev = rev * 10 + digit;
            x = x / 10;
        }   
        System.out.println(rev);

        


    }
    }}
