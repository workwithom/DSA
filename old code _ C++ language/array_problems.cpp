#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

#include<climits>
using namespace std;

  // lecture 14  


/*
/q1...target sum: sum of pair of numbers= intput x. count that pairs.
int array[]={3,4,6,7,1};
int tsum,count=0;
cout<<"enter target sum: ";
cin>>tsum;

int size =sizeof(array)/sizeof(array[0]);

for(int i=0;i<size;i++){
    for(int j=i ;j<size;j++){
      if (array[i]+array[j+1]==tsum)
        count++;

    }

}
cout<<"pairs:"<<count<<endl;


*/

//Q 2.. find the second largest no. in a given array;

/*
int lEi(int array[],int size)
{

 int max=INT_MIN;
 int maxindex=-1;
    for(int i=0;i<size;i++){
     if (array[i]>max){
         max=array[i];
         maxindex=i;}

       }
return maxindex;}
int main(){
int array[]={1,2,3,4,5};
int size=5;

*/

/*
int lEI=lEi(array,10);
int max=array[lEI];
cout<< "max ele : "<<array[lEI]<<endl;





for(int i=0;i<size;i++){
  if(array[i]==max)
    array[i]=-1;
    

}

for(int ele:array){
  cout<<ele;

}
cout<<endl;

int sec_max=0;

for (int i=0;i<size;i++){
   if(array[i]>array[i-1] )
    sec_max=array[i];

}
cout<<"second max :"<< sec_max;


// second (less traverse) method;

int max=INT_MIN,sec_max=INT_MIN;

for(int i=0;i<size;i++)
{ if(max<array[i])
   max=array[i];

}

cout<<max<<endl;

for(int i=0;i<size;i++)
{  if(array[i]>sec_max && array[i] !=max)
    sec_max=array[i];

}
cout <<"sec max: "<<sec_max;

*/

// Q 4 rotating the array :
/*
int k;
cin>>k;
k=k%size;

int array1[10];
int j=0;

for(int i=size-k;i<size;i++){   
 
  
    array1[j++]=array[i];
  }

for(int i=0;i<size-k;i++){
  array1[j++]=array[i];




 }
 for(int ele:array1){
  cout<<ele;
 }
*/


/*
// rotating an array using reverse;


int main()
{

vector<int>v;
v.push_back(1);
v.push_back(2);
v.push_back(3);
v.push_back(4);
v.push_back(5);

int k;
cin>>k;
k=k%v.size();

reverse(v.begin(),v.end());
reverse(v.begin(),v.begin()+k);
reverse(v.begin()+k,v.end());

for(int i=0;i<v.size();i++)
{
  cout<<v[i]<<endl;

}
*/

/*
// if an element is present in the array or not.

int main(){
int n;
cin>>n;

vector <int>v(n);
for(int i=0;i<n;i++){
 cin>>v[i];

}

const int N = 1e5 + 10;
vector<int> freq(N,0);



for(int i=0;i<n;i++){
  freq[v[i]]++;

}
cout<<"enter queries: "<<endl;
int q;
cin>>q;

while(q--)
  {int queryelement;

   cin>>queryelement;
   

  cout<<freq[queryelement]<<" ";

  }

}

*/


// lecture 15 array 2 (two pointer problems in array)

//Q1. sorting 0 and 1.
/*
void sort0n1(vector<int>&array)
{  
   int zero_count =0;
    for(int i=0;i<array.size();i++)
      {if(array[i]==0) 
       {zero_count++;}
      }
    for(int i=0;i<array.size();i++)
    { if(i<zero_count)
        array[i]=0;
      else
         array[i]=1;
             }

}
int main(){
int n;
cin>>n;


vector <int>v(n);
for(int i=0;i<n;i++){
 cin>>v[i];


}
sort0n1(v);

for(int ele:v)
  {
    cout<<ele<<" ";
  } 

}*/
// if we  have to do it with only traversing by one , then 
/*
void sortarray (vector<int>&array){
  int leftele=0,rightele=array.size()-1;

 while(leftele<rightele){
 if (array[leftele]==1  && array[rightele]==0){
     array[leftele++]=0;
     array[rightele--]=1;

   }
 if(array[leftele]==0)
  {leftele++;}
  if (array[rightele]==1){
    rightele--;

  } 

 }
 
}

int main(){
int n;
cin>>n;


vector <int>v(n);
for(int i=0;i<n;i++){
 cin>>v[i];


}
sortarray (v);

for(int ele:v)
  {
    cout<<ele<<" ";
  } 

}
*/



// even should in left and rest should in right  
/*
void sortarray (vector<int>&array){
  int leftele=0,rightele=array.size()-1;

 while(leftele<rightele){
 if (array[leftele]%2 != 0  && array[rightele]%2==0){
    int x=array[leftele]; //or can use swap(array[leftele],array[rightele]);

     array[leftele++]=array[rightele];
     array[rightele--]=x;
   }
 if(array[leftele]%2==0)
  {leftele++;}
  if (array[rightele]%2!=0){
    rightele--;

  } 

 }
 
}

int main(){
int n;
cin>>n;


vector <int>v(n);
for(int i=0;i<n;i++){
 cin>>v[i];


}
sortarray (v);

for(int ele:v)
  {
    cout<<ele<<" ";
  } 

}


// Q3. array 'a' is in non decreasing order , return a array of squares
//         of elements of array 'a' in non decreasing order .


void sortsquare(vector<int>&v){
 
 vector<int>ans;

 
  int leftptr =0;
  int rightptr=v.size()-1;
   
 while(leftptr<=rightptr){
    if (abs(v[leftptr])<abs(v[rightptr])){
      ans.push_back(v[rightptr]*v[rightptr]);
      rightptr--;}
 
    else{
      ans.push_back(v[leftptr]*v[leftptr]);
      leftptr++;
    }}
reverse(ans.begin(),ans.end());

  for(int i=0;i<ans.size();i++)
  {cout<<ans[i]<<"  ";
}cout<<endl;
}

int main (){
 int n ;
 cin>>n;

vector<int > v;
for(int i=0;i<n ;i++){
  int ele;
  cin>>ele;
  v.push_back(ele);


}

sortsquare(v);



}


*/

// lecture 16;array 3

// Q1.array manipulation where next ele is sum of prefix sum ;

/*
void prefix_sum(vector<int>&v){
  
for(int i=1;i<v.size();i++){
    v[i]+=v[i-1];
}
for(int ele:v){
  cout<<ele<<" ";

}
}
int main(){
int n;
cin>>n;

vector<int>v;
for(int i=0;i<n;i++){
 int ele;
  cin>>ele;
 v.push_back(ele);
}
prefix_sum(v);




}

*/

//Q2. sum of prefix = sum of suffix , find that point.without using another new ARrray 

//error in this question;

bool prefixsuffixequal(vector<int>&v)
{ int prifix=0;

int total=0;

  for (int i=0;i<v.size();i++){
     total+=v[i];}
  for (int i=0;i<v.size();i++){
     prifix+=v[i];
    int suffix =total-prifix;
    
    if(prifix==suffix){
        return true;}
    
      else{
        return false;}
  }
}

  




int maim(){

  int n;
cin>>n;

vector<int>v;
for(int i=0;i<n;i++){
 int ele;
  cin>>ele;
 v.push_back(ele);
}

prefixsuffixequal(v);



}


/*

//Q3. answer q queries where you need to print sum of values  btw given range indices, l to r.



int main(){

cout<<"array length: ";
int n;
cin>>n;

vector<int>v(n+1,0);


for(int i=1;i<=n;i++){
  
  cin>>v[i];


}
for(int ele:v){
  cout<<v[ele];

}

for(int i=1;i<=n;i++){
  v[i]+=v[i-1];

}
int q;
cout<<endl<<"queries: ";

cin>>q;
int ans=0;            //51234 q 1,3 ans 8 

while(q--)
{
  int l,r;
  cin>>l>>r;

 ans= v[r]-v[l-1];

cout<<ans<<" ";

}

}




*/






















