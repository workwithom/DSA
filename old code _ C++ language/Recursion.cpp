#include <iostream>
using namespace std;
// lecture 27 : recursion 

// factorial calculation
/*
int f(int a){
    if(a==1)return 1;
    return  a*f(a-1);  // factorial(n) = n X factorial(n-1)

}
int main(){
    int result=f(5);
    cout<<result;
    return 0;

}
*/
// program to find nth fiboacci number

// by itrated approach-
/*
int main(){
    int arr[200];

   
    int x;
    arr[0]=0;
    arr[1]=1;
    int i=2;
    cin>>x;
    if(x<2) {
        cout<<arr[x]<<endl;}
    else{
        while(i<=x){
            arr[i]=arr[i-1]+arr[i-2];
            if (i==x) {
                cout<<arr[x];
                break;
            }
            i++;
        }

    }
return 0;
}



// by recursion approach
int nth_fib(int n){
    if (n==0 || n==1) return n;
    int result = nth_fib(n-1) + nth_fib(n-2);
    return result;
}
int main(){
    int x;
    cin>>x;
    int result = nth_fib(x);
    cout<<result;
 return 0;
}
*/

//lecture 28 

// Q 1. given an integer 'x' . find out the sum of its digits using recusion   
/*
int sumod(int n){
    if (n>=0 && n<=9){
        return n;
    }
    return n%10 + sumod(n/10) ;
}

int main(){
    int x;
    cin>>x;
    int result=sumod(x);
    cout<<"sum is: "<<result;
return 0;    
}
*/

// Q 2. given two no. p and q , find the value of p^q using recursive funtion
/*
// time complexity =O(n)
int power(int a, int b){
    if (b==0) return 1;
    int result ;
    result=a *( power(a,b-1));
    return result;
} 
// time complexity =O(log n)
int power_ef(int a,int b){
    if(b==0)return 1;
    if(b%2==0){
        int result=power_ef(a,b/2);
        return result * result;

    }else{
        int result = power_ef(a,(b-1)/2);
        return a * result*result;
    }
}
int main(){
    int p,q;
    cin>>p>>q;
    int result1=power(p,q);
    int result2=power_ef(p,q);
    cout<<"p^q O(n) is  : "<<result1<<endl;
    cout<<"p^q O(log n) is  : "<<result2;
 return 0;
 }
*/

//lecture 29 :problem solving on rec.
/* 
 //Q2. max form array
#include<iostream>
using namespace std;

int f(int *arr,int idx,int x){
    
    if(idx == x){ 
        return arr[idx];
    }
    return max(arr[idx],f(arr,idx+1,x));
}

int main(){
        int x,idx=0;
        cin>>x;
        
       int arr[]={1,4,10,6,7};
       int max= f(arr,idx,x);
       cout<<max<<endl;
    return 0;}

// Q2. sum of array's elements


int f(int *arr,int idx,int x){
    
    if(idx == x-1){ 
        return arr[idx];
    }
    return arr[idx]+f(arr,idx+1,x);
}

int main(){
        int x,idx=0;
        cin>>x;
        
       int arr[]={1,4,10,6,7};
       int sum= f(arr,idx,x);
       cout<<sum<<endl;
    return 0;}
 */       

//  lecture 30

// Q 1. remove all occurance of 'a' from a string s="abcax".
/*
string f(string &s,int idx,int n){
    if(idx==n)return "";
    string curr="";
    curr+=s[idx];

    return ((s[idx]=='a')? "":curr)+f(s,idx+1,n);
}
int main(){
    string s="abcax";
    int n=5;
    cout<<f(s,0,n);
return 0;
}
*/
 
 // Q 2. check the given no. 12621 is palidnrome or not.
 /*
bool f(int num,int *temp){
    //base case
    if(num>=0 && num<=9){
        int lastDigitOfTemp=(*temp)%10;
        (*temp)/=10;
        return (num==lastDigitOfTemp);
    }
    bool result= f(num/10,temp) && num%10 == ((*temp)%10);
     (*temp)/=10;
    return result;
}

int main(){
    int num=12621;
    int anotherNum=num;
    int *temp=&anotherNum;
    cout<<f(num,temp);
    return 0;
}

*/
