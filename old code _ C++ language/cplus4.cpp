#include<iostream>
using namespace std;

int main()
{
    int a,b,c;

    cin>>a;
    cin>>b;
    cout<<(a==b);
     cout<<(a!=b);
      cout<<(a>b);
       cout<<(a<=b);
        cout<<(a<b);

    bool exp1=true;
    bool exp2=false;

   cout<<endl;
   
    cout<<(exp1&&exp2)<<endl; //false
     cout<<(exp1||exp2)<<endl;//true
      cout<<(!exp2)<<endl;//true
       cout<<(!exp1)<<endl;//false
        cout<<(exp1&&exp2)<<endl;
        

    return 0;


}