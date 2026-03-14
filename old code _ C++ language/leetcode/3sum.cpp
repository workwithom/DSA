#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main (){
     vector<int> v = {-1,0,1,2,-1,-4};
     int n=v.size();
    if(n<3) {
        cout <<"no triplet";
        return 0;
    }

    sort(v.begin(),v.end());
    vector<vector<int>>ans;

    for(int i=0;i<n-2;i++){
        if (i > 0 && v[i] == v[i - 1]) continue;
       
    int left=i+1;
    int right=n-1;

    while(left<right){
        int sum=v[i]+v[left]+v[right];
        if(sum==0){
            ans.push_back({v[i],v[left],v[right]});
            while (left < right && v[left] == v[left + 1]) left++;
            while (left < right && v[right] == v[right - 1]) right--;    
            left++;
            right--;
        } else if (sum<0){
            left++;
        }else{
            right--;
        }
    }  
    }
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0; 
}
