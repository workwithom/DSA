
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

// Lecture 35:
// bubble sort algorithm :  sorting an vector.

// bubble sort is a stable algorithrm i.e  30,30* is remained sort.
 /*
void BubbleSort(vector<int>& v){
    for(int i=0;i<v.size()-1;i++){
        bool flag=false;                       //use for optimize time compx.  
        for(int j=0;j<v.size()-i-1;j++){
            if(v[j]>v[j+1]){ 
                flag=true;
                swap(v[j],v[j+1]) ;
            }    
        }
        if(!flag) break;
    }
}
int main(){
    int n;
    cin>>n;
    vector<int> v;
    for ( int i = 0; i < n ; i++ ){
        int x;
        cin>>x;
        v.push_back(x);
    }
    for ( int i = 0; i < n ; i++ ){
        cout<<v[i];
    }
    BubbleSort(v);
    cout<<"\n";
    for ( int i = 0; i < n ; i++ ){
        cout<<v[i];
    }
    return 0;
    }
*/
// lecture 36 :
// selection sort algorithms.
/*
void SelectionSort(vector<int>& v){
    for(int i=0;i<v.size()-1;i++){
        bool flag=false;                     //use for optimize time compx.
        int min_idx=i;                       
        for(int j=i+1;j<v.size();j++){
            if(v[j]<v[min_idx]){ 
                flag=true;
                min_idx=j;
            }    
        }
        if(min_idx!=i) swap(v[i],v[min_idx]);
        if(!flag) break;
    }
}
int main(){
    int n;
    cin>>n;
    vector<int> v;
    for ( int i = 0; i < n ; i++ ){
        int x;
        cin>>x;
        v.push_back(x);
    }
    for ( int i = 0; i < n ; i++ ){
        cout<<v[i];
    }
    SelectionSort(v);
    cout<<"\n";
    for ( int i = 0; i < n ; i++ ){
        cout<<v[i]<<" ";
    }
    return 0;
    }
*/
// home work for max selection sort algo.
/*
void SelectionSortMax(vector<int>&v){
    int n=v.size();
    
    for(int i=n-1;i>0;i--){
        int max_idx=i;
        for(int j=0;j<i;j++){
            if(v[max_idx]<v[j]){
                max_idx=j;

            }
        }
        if(max_idx!=i) swap(v[i],v[max_idx]);
     }


}

int main(){
    int n;
    cin>>n;
    vector<int> v;
    for ( int i = 0; i < n ; i++ ){
        int x;
        cin>>x;
        v.push_back(x);
    }
    for ( int i = 0; i < n ; i++ ){
        cout<<v[i];
    }
    SelectionSortMax(v);
    cout<<"\n";
    for ( int i = 0; i < n ; i++ ){
        cout<<v[i]<<" ";
    }
    return 0;
    }
*/

// lecture 37: insertion sort . 

/*
void insertionSort(vector<int>& v){
    for(int i=1;i<v.size();i++){
        int cur_ele=v[i];
        int j=i-1;
        while(j>=0 && v[j]>cur_ele){
            v[j+1]=v[j];
            j--;
        }
        v[j+1]=cur_ele;

    }
}
int main(){
    int n;
    cin>>n;
    vector<int> v;
    for ( int i = 0; i < n ; i++ ){
        int x;
        cin>>x;
        v.push_back(x);
    }
    for ( int i = 0; i < n ; i++ ){
        cout<<v[i];
    }
    insertionSort(v);
    cout<<"\n";
    for ( int i = 0; i < n ; i++ ){
        cout<<v[i]<<" ";
    }
    return 0;
    }
*/

// lecture 38 : problem solving on sorting algorithms 1 .

//   Q 1 . given an integer array arr , move all 0's to the end of it while maintaining
//         the relative order of the non-zero elements.
//        note that you must do this in-place without making a copy of the array.
/*

void swapZeroesToEnd(vector<int>&v){
    int n=v.size();
    // my method

    // for(int i=0;i<v.size();i++){
    //     bool flag= false;
    
    //     int lastNonZero=v.size()-i;

    //     for(int j=0;j<=lastNonZero;j++){
    //         if(v[j]==0 && v[j]!=v[j+1]){
    //             swap(v[j],v[j+1]);
    //             lastNonZero--;
    //             flag=true;
    //         }
    //     }
    //     if(!flag) break;
    // }

// ma'am method
    for(int i=n-1;i>=0;i--){
        bool flag=false;
        int j=0;
        while(j!=i){
            if(v[j]==0 && v[j+1]!=0){
                swap(v[j],v[j+1]);
                            
                flag = true;
            }
            j++;

        }
        if(!flag) break;
    }
return;

}

int main(){
    int n;
    cin>>n;
    vector<int> v;
    for ( int i = 0; i < n ; i++ ){
        int x;
        cin>>x;
        v.push_back(x);
    }
    for ( int i = 0; i < n ; i++ ){
        cout<<v[i];
    }
    swapZeroesToEnd(v);
    cout<<"\n";
    for ( int i = 0; i < n ; i++ ){
        cout<<v[i]<<" ";
    }
    return 0;
    }
*/

 // Q.2. given an array of names of fruits , you are supposed to sort it in lexicographical order using the selection sort. 
 //     input : sim , tea , sit   output : sim , sit , tea
/*
void selectionSort(char fruit[][60],int n){
    for(int i=0;i<n-1;i++){
        //finding minimum element
        int min_idx=i;
        for(int j=i+1;j<n;j++){
            if(strcmp(fruit[min_idx],fruit[j]) > 0 ){
                min_idx=j;
            }
        }
        //place the element at the beginning
        if(min_idx!=i) {
            swap(fruit[i],fruit[min_idx]);
            
        }
    }
return;
} 

int main(){
    char fruit[][60]={"papaya","lime","watermelon","apple","mango","kiwi"};
    int n=sizeof(fruit)/sizeof(fruit[0]);
    selectionSort(fruit,n);

    for(int i=0;i<n;i++){
        cout<<fruit[i]<<" ";
        cout<<endl;
    }
return 0;    
}
*/

// lecture 39 : merge sort algorithm .
/*

void merge(int arr[],int l,int mid, int r){
    
    int an=mid-l+1;
    int bn=r-mid;

    //create two temp arrays:
    int a[an];
    int b[bn];

    for(int i=0;i<an;i++){
        a[i]=arr[l+i];
    }
    for(int j=0;j<an;j++){
        b[j]=arr[mid+1+j];
    }
    int i=0;  //initial poition of a array.
    int j=0;  //initial poition of b array.
    int k=l;  //in+itial poition of merged array i.e arr .

    while (i<an && j<bn){
        if(a[i]<=b[j]){     // if a[i]==b[j] ????? problem solved :)
            arr[k++]=a[i++];
        }
        else{
            arr[k++]=b[j++];
        }
    }
    while(i<an){
        arr[k++]=a[i++];
    }
    while(j<bn){
        arr[k++]=b[j++];
    }
}
void mergeSort(int arr[],int l , int r){
    // base case:
    if(l>=r) return;
    int mid= (l+r)/2;
    mergeSort(arr,l,mid);
    mergeSort(arr,mid+1,r);
    merge(arr,l,mid,r);
    return;
}

int main(){
    int arr[]={10,28,24,6,34,18,38,44};
    int n=sizeof(arr)/sizeof(arr[0]);

    mergeSort(arr,0,n-1);

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";

    }
return 0;
}

*/


// # lecture : 40 : Quick Sort Algorithm


int partition(vector<int>& arr,int first,int last){
    if(first>=last) return first;
    int i=first-1;
    int j=first;
    int pivot=last;

// there is meaiad no. of array is not possible . then we pick random element.
//  int pivot index= first + rand()%(last-first+1);
    while(j<last){
        if(arr[j]<arr[pivot]){
            i++;
            swap(arr[i],arr[j]);
            j++;
        }
        else{
            j++;
        }
    }
    swap(arr[i+1],arr[pivot]);
    return i+1;
}

void QuickSort(vector<int>& arr,int first,int last){
    if(first>=last) return;
    int pi=partition(arr,first,last);
    QuickSort(arr,first,pi-1);
    QuickSort(arr,pi+1,last);
    return;
}

int main(){
    vector<int> v={18,12,16,20,35,30};
    QuickSort(v,0,v.size()-1);
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
return 0;
}

