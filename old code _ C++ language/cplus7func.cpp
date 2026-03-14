#include<iostream>
using namespace std;


//sum funtion

 
int add(int num1,int num2)
{ int a=6,b=7;


    int sum=num1+num2;
return sum;
}
int main (){
int a=4,b=5;
 int z= add(a,b);
cout<<z<<endl;
cout<<a<<endl<<b;


return 0;}


/*
int add(int num1,int num2,int num3=5){//'default parameters are always put in last parameter'
    int sum = num1+num2+num3;
    return sum;

}
void change_Value(int &z, int &y){
   z=100;
   y=99;

}
int main(){
 int a=5;
 int b=6;

change_Value(a,b);
cout<<a<<endl<<b<<endl;

cout<<add(a,b);


return 0;}
*/

/*
ROADMAP FOR FRONT END DEVLOPMENT;

HTML
VANILLA CSS
   BOOTSTRAP
 *  TAILWIND CSS
JAVASCRIPT
VERSION CONTROL system
   GIT AND GIT HUB
   SAAS 
   TESTING
   CRYPASS
   TYPESCRIPT
   */


//  *revision of FUNCTION *

/* q1
int square(int x){
  return x*x;

 }
 int main (){
   int x;
   cin>>x;

for( int i=1 ;i<=x;i++){
  cout<<square (i)<<endl;

 }}
*/


/* q2
 double circ(int r){
 return 2*3.14*r;


 }

double area (int r){
   return 3.14*r*r;

}

int main(){
  int r;
  cin>>r;
  cout<<circ(r)<<endl<<area(r);


}
*/

/*/q3 voting

bool checkeligibility(int age){
 if (age >= 18)
   return true;
 else
   return false;

 
 

}
int main(){
   int age;
   cin>>age;
   int result=checkeligibility(age);

 if (result)
  cout<<"yess";
 else
  cout<<"no";
  
}
// Q4 print odd num betw two numbers...

bool oddnum(int x)
 {if (x%2==0)
  return true;
  else 
  return false;
  }
  int main ( ){
   int a,b;
   cin>>a;
   cin>>b;

   

   for(int i=a;i<=b;i++){
   
      if(oddnum(i))
       continue;

      else
       cout<<i;

      
   }
  }
  ,,

 //q5
bool isprime(int x){
   for(int i=2;i<=x-1;i++)
  { if (x%i==0)
    return false;}
 return true;}
int main (){
   int r;
   cin>>r;
   cout<<"checking the primes upto "<<r<<endl;
 for(int i=2;i<=r;i++){
   if(isprime(i))
   cout<<i<<endl;

}}*/
 