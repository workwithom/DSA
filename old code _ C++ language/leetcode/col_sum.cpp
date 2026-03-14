#include <iostream>
#include <vector>
using namespace std;
int main() {
    vector<vector<int>> v = {{1, 2, 3}, {1, 2}, {1, 2, 3, 4}};
    
    int maxrow=v.size();
    int maxcol=0;
    
    for(int i=0;i<v.size();i++){
       for(int j=0;j<v[i].size();j++){ 
           if(maxcol<j){
               maxcol=j+1;
           }
       }
    }  
    
    int sum[maxcol] = {0};
    for(int i=0;i<v.size();i++){
       for(int j=0;j<v[i].size();j++){ 
           sum[j]+=v[i][j];
          
       }
    }
    for(int i =0;i<maxcol;i++){
        cout<<sum[i]<<endl;
    }
    
    
    return 0;
}