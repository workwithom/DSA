#include<iostream>
using namespace std;
int main()
{
int line_no;
cin>>line_no;
 

for (int i=1;i<=line_no;i++){
    for (int k=0;k<line_no-i;k++){
     cout<<'_';

     }
  for(int j=0;j<i*2 -1;j++)
  {
    
      
         cout<<(char)('A'+j);
  }


  
 cout<<endl;
}

for(int i=1;i<line_no;i++) 
   {
    
    for (int k=1;k<=i;k++){
      cout<<'_';
 }
   for(int j=0;j<(2*line_no-(2*i)-1);j++)
      {
        cout<<(char)('A'+j);
      }
 cout<<endl;
   }
return 0;
} 