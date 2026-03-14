#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#include <climits>
#include <algorithm>
using namespace std;


// lecture 41 : Count Sort  &  Radix Sort
 
 /*
void countSort(vector<int>&v){
    int n=v.size();
    // find max element
   //int max=INT_MIN;
    int max=v[0];
    for(int i=0;i<n;i++){
        if(max<v[i]){
            max=v[i];
        }
    }
    // create the freq array
    vector<int>freq(max+1,0);
    for(int i=0;i<n;i++){
        freq[v[i]]++;
    }
    // calculate cumulative freq
    for(int i=1;i<=max;i++){
        freq[i]+=freq[i-1];
    } 


    //ans array
    vector<int>ans(n);
    for(int i=n-1;i>=0;i--){
        ans[--freq[v[i]]]=v[i];
    }
    //copy back the answers to org array
   

}

int main(){
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    countSort(a);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
return 0;
}

*/


//    :->  radix sort

/*
void CountSort(vector<int>&v,int n,int max,int pos){
    vector<int> freq(10,0);
    vector<int> ans(n);
     
    for(int i=0 ; i<n;i++){
        freq[(v[i]/pos)%10]++;
    }
    for(int i=1; i<10;i++){
        freq[i]+=freq[i-1];
    }
    for(int i=n-1;i>=0;i--){
        ans[--freq[(v[i]/pos)%10]]=v[i];
    }
     for(int i=0;i<n;i++){
        v[i]=ans[i];
    }
}
void radixSort(vector<int>&v){
    int n=v.size();
    // find max element
    int max_ele=INT_MIN;
    
    for(int i=0;i<n;i++){
        max_ele=max(v[i],max_ele);
    }
    for(int pos=1; max_ele/pos>0;pos*=10){
        CountSort(v,n,max_ele,pos); }
}

int main(){
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    radixSort(a);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
return 0;
}
*/


// lecture 41: part 2 : BUCKET SORT 

//method 1 ; for numbers between 0 and 1;
/*
void bucketSort(float arr[],int size){
    //step1: create bucket array
    vector<vector<float>> bucket(size,vector<float>());
    //step2: inserting elements in buckets
    for(int i=0;i<size;i++){
        int index=arr[i]*size;
        bucket[index].push_back(arr[i]);
    }
    //step3: sorting individual buckets
    for(int i=0;i<size;i++){
        if(!bucket[i].empty()){
            sort(bucket[i].begin(),bucket[i].end());
        }
    }
    //step4: combining elements from buckets
    int k=0;
    for(int i=0;i<size;i++){
        for(int j=0;j<bucket[i].size();j++){
            arr[k++]=bucket[i][j];
        }
    }

}

int main(){
    float arr[]={0.13,0.45,0.12,0.89,0.75,0.63,0.85,0.39};
    int size=sizeof(arr)/sizeof(arr[0]);
    bucketSort(arr,size);

    for(int i=0;i<size;i++){
        cout<<arr[i]<<" > < ";
    }

return 0;    
}
*/

// method 2 : for num can more than 1 also;

void bucketSort(float arr[],int size){
    //step1: create bucket array
    vector<vector<float>> bucket(size,vector<float>());

    // finding range 
    float max_ele=arr[0];
    float min_ele=arr[0];
    for(int i=1;i<size;i++){
        max_ele=max(max_ele,arr[i]);
        min_ele=min(min_ele,arr[i]);
    }
    float range=(max_ele-min_ele)/size;

    //step2: inserting elements in buckets
    for(int i=0;i<size;i++){
         int index=(arr[i]-min_ele)/range; 
        // boundary condition
        float diff = (arr[i]- min_ele)/range - index;
        if(diff==0 && arr[i]!=min_ele){
        bucket[index-1].push_back(arr[i]);
        }
        else{
        bucket[index].push_back(arr[i]);
        }
    }

    //step3: sorting individual buckets
    for(int i=0;i<size;i++){
        if(!bucket[i].empty()){
            sort(bucket[i].begin(),bucket[i].end());
        }
    }
    //step4: combining elements from buckets
    int k=0;
    for(int i=0;i<size;i++){
        for(int j=0;j<bucket[i].size();j++){
            arr[k++]=bucket[i][j];
        }
    }

}

int main(){
    float arr[]={6.13,1.89,0.12,3.89,0.75,0.63,0.85,10.39};
    int size=sizeof(arr)/sizeof(arr[0]);
    bucketSort(arr,size);

    for(int i=0;i<size;i++){
        cout<<arr[i]<<" > < ";
    }

return 0;    
}

