#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

#include<climits>
using namespace std;
// multiplication of matrix



// #18 pascal tringle problems

// first method : n C r method 
int factorial(int x){
    int a=1;
    if(x==0){
        return 1;
    }
    for(int i=1;i<=x;i++){
        a=a*i;
    }
    return a;
}

vector<vector<int>> pascaltriangle(int n){
    vector<vector<int>>pascal(n);
    
    for(int i=0;i<n;i++){
        pascal[i].resize(i+1);
        for(int j=0;j<i+1;j++){
            pascal[i][j]=(factorial(i))/(factorial(j)*factorial(i-j));
        }
    }
    return pascal;

}


int main(){
    int n;
    cin>>n;
    vector<vector<int>>ans;

    ans=pascaltriangle(n);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){//ans[i] is for no. of ele in i th row
            cout<<ans[i][j];}
        cout<<endl;
    }
}


//second method : 
/*
vector<vector<int> > pascaltriangle(int n){
    vector<vector<int>>pascal(n);
    
    for(int i=0;i<n;i++){
        pascal[i].resize(i+1);
        for(int j=0;j<i+1;j++){
            if(j==0 || j==i){
                pascal[i][j]=1;
            }else{
            pascal[i][j]=pascal[i-1][j]+pascal[i-1][j-1];
        }}
    }
    return pascal;

}


int main(){
    int n;
    cin>>n;
    vector<vector<int>>ans;

    ans=pascaltriangle(n);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){//ans[i] is for no. of ele in i th row
            cout<<ans[i][j];}
            cout<<endl;
            

    }
}
*/