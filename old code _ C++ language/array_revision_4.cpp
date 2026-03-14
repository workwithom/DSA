#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

#include<climits>
using namespace std;
/*
// Q1..   given arr1=1,3,5,8,9  arr2=2,4,6,7 both are already sorted 
//  make new ansarray which contains elements of both arrays in sorted form .
        
int main(){
    int arr1[5]={1,3,5,8,9};
    int arr2[4]={2,3,6,7};
    int ans[9];
int m=5, n=4;

    int i=0;
    int j=0;
    int k=0;

    while (i<m and j<n){ 
        // this loop work before exhaust
        
        if (arr1[i]<arr2[j]){
            ans[k++]=arr1[i++];

        }
        else {
            ans[k++]=arr2[j++];

        }

    }
    while(j<n){
        // this work after array 1 exhausted;

        ans[k++]=arr2[j++];

    }
    while(i<m){
        // this work after array 2 exhausted
        ans[k++]=arr1[i++];

    }
    for(int i=0;i<m+n;i++){
    cout<<ans[i]<<" ";
    }
}

*/

// Q2 ... given a vector arr[] are shorted in increasing order of size n and integer x ,
//       find if there exists a pair inthe array whose sum is exactly x.
/*
//my method 
 bool checkpair(vector< int >v,int x){
    
    for(int i=0;i <8;i++){
        for(int j=i+1;j <8;j++){
            if(v[i]+v[j]==x){
                return true;
                
            }

        }
    }
    return false;


   }

int main(){
    vector <int>arr;
    int n = 8;

    for (int i=0;i<n;i++){
        int k;
        cin>>k;
        arr.push_back(k);

    }
    cout<<"enter x:";

    int x;
    cin>>x;



    bool ans=checkpair(arr,x);
    if(ans==true){cout<<"YES";
    }
    else{cout<<"NO";
    }
}
*/
// sir metohd
/*
int main(){
    vector <int>arr;
    int n = 8;

    for (int i=0;i<n;i++){
        int k;
        cin>>k;
        arr.push_back(k);

    }
    cout<<"enter x:";

    int x;
    cin>>x;

    int i=0;
    int j=n-1;
    bool found=false;

    while (i<j){
        if(arr[i]+arr[j]==x){
            found= true;
            break;

        }
        else if(arr[i]+arr[j]<x){
            i++;
        }
        else{
            j--;

        }
    }
    if(found==true){cout<<"YES";
    }
    else{cout<<"NO";
    }
}    
*/

// Q 3 ...given a vector arr[] are shorted in increasing order of size n and integer x ,
//       find if there exists a pair in the array whose absolute difference is exactly x.

//.. this solution contains two pointers i at start and j at end .
//     but it is  not work here
/*
int main(){
    vector <int>arr;
    int n = 8;

    for (int i=0;i<n;i++){
        int k;
        cin>>k;
        arr.push_back(k);

    }
    cout<<"enter x:";

    int x;
    cin>>x;

  int i=0;
    int j=n-1;
    bool found=false;

    while (i<j){                //.. this solution not work here
        if(abs(arr[i]-arr[j])==x){
            found= true;
            break;

        }
        else if(abs(arr[i]-arr[j])>x){
            j--;
        }
        else{
            i++;

        }
    }
    if(found==true){cout<<"YES";
    }
    else{cout<<"NO";
    }
} */    

// we use both pointers at begining to get the desired output 
/*
int main(){
    vector <int>arr;
    int n = 5;

    for (int i=0;i<n;i++){
        int k;
        cin>>k;
        arr.push_back(k);

    }
    cout<<"enter x:";

    int x;
    cin>>x;

  int i=0;
    int j=1;
    bool found=false;

    while(i<n && j<n){
        if(abs(arr[i]-arr[j])==x){
            found=true;
            break; 
        }
        else if(abs(arr[i]-arr[j])<x){
            j++;
        }
        else{
            i++;

        }
    }
    if(found==true){cout<<"YES";
    }
    else{cout<<"NO";
    }
}     */

// Q 4... given a array sorted in increasing order return an array of square
//    of each number sorted in increasing order where size of vector 1<size<101..

void squarearray(vector<int>arr,int size){
    int resultarr[size];
    int i=0;
    int j=size-1;
    int k=size-1;
    while(i<=j && k>=0){
        if(abs(arr[i])<abs(arr[j])){
            resultarr[k]=arr[j]*arr[j];
            k--;
            j--;
//            resultarr.push_back(arr[i]*arr[i]);
        }
        else{
            resultarr[k]=arr[i]*arr[i];
            k--;
            i++;
//            resultarr.push_back(arr[j]*arr[j]);
        }
    }
    for(int i=0;i<size;i++){
        cout<<resultarr[i]<<" ";
    }

}


int main(){
    vector <int>arr;
    int n = 6;

    for (int i=0;i<n;i++){
        int k;
        cin>>k;
        arr.push_back(k);

    }
    squarearray(arr,n);
return 0;
}


