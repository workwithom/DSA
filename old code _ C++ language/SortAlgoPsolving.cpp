#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#include <climits>
#include <algorithm>

using namespace std;

// lecture 42: problem solving on sorting algorithms-2 

// Q 1 : write a program to find Kth smallest element in an array using Quick Sort.


int partition(int arr[], int l, int r) {
    int pivot = arr[r];
    int i = l - 1;
    for (int j = l; j < r; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[r]);
    return i + 1;
}


int Kthsmallest(int arr[],int l,int r,int k){
    if(k>0 && k<=r-l+1){
        int pos=partition(arr,l,r);
       
        if(pos-l == k-1) return arr[pos];
        if(pos-l>k-1){
            return Kthsmallest(arr,l,pos-1,k);
        }
        else{
            return Kthsmallest(arr,pos+1,r,k-pos+l-1);
        }
    }
    return INT_MAX;
}

int main(){
    int arr[]={3,5,2,1,4,7,8,6};
    int size=sizeof(arr)/sizeof(arr[0]);
    int k;
    cin>>k;
    cout<<Kthsmallest(arr,0,size-1,k);
return 0;    
}


// Q 2. given two sorted arrays, merge them in a sorted manner.
/*
void mergesort(int arr1[],int arr2[]){
    int arr1size=3;
    int arr2size=3;
    // result array
    int ans[arr1size+arr2size];
    int k=0;
    int i=0;
    int j=0;
    while(i<arr1size && j<arr2size){
        if (arr1[i]<=arr2[j]){
            ans[k++]=arr1[i];
            i++;
        }
        else{
            ans[k++]=arr2[j];
            j++;
        }
    }
    while(i<arr1size){
        ans[k++]=arr1[i];
        i++;
    }
    while(j<arr2size){
        ans[k++]=arr2[j];
        j++;
    }
    
    for(int i=0;i<arr1size+arr2size;i++){
        cout<<ans[i]<<" ";
    }
}

int main(){
    int num1[]={5,8,10};
    int num2[]={2,7,8};
    mergesort(num1,num2);

return 0;    
}
*/