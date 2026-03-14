#include<iostream>
#include<vector>
using namespace std;

int main () {

    vector<int> nums={-2,-2,-2};
    int k=3;
    
       int max_idx=0;
       int max=0;
    for(int i=0;i<k;i++){
    
        for(int j=0;j<nums.size()-1;j++){
            if(nums[max_idx]<nums[j+1]){
                
                max_idx=j+1;
            }
            else if(nums[max_idx]<=0 && nums[max_idx]>nums[j+1]){
                 max_idx=j+1;
            }
        }
        max=nums[max_idx];
        nums[max_idx]=0;
    }


        cout<<max<<endl;
}
