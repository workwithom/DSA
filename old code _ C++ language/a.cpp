#include<iostream>
#include<vector>
using namespace std;

bool prefixsuffixequal(vector<int>&v)
{ int prifix=0;
int suffix=0;
int total=0;

  for (int i=0;i<v.size();i++){
     total+=v[i];
  for (int i=0;i<v.size();i++){
     prifix+=v[i];
     suffix+=total-prifix;
    if(prifix==suffix){
        return true;}
    else{
      return false;
    }    
}

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