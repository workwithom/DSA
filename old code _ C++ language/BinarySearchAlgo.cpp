#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#include <climits>
#include <algorithm>


using namespace std;

// lecture 44 : binary search algorithm

// example:  find out the index of target element in an given array.

/*
int binarysearch(vector<int> &v, int target) {
    int lo = 0;
    int hi = v.size() - 1;
    while (lo <= hi) { 
        int mid = lo + (hi - lo) / 2;
        if (target == v[mid]) {
            return mid;
        } else if (target < v[mid]) {
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    return -1;
}

int main() {
    vector<int> v;
    for (int i = 0; i < 7; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end()); // Sort the input array
    int target;
    cin >> target;
    cout << binarysearch(v, target);
    return 0;
}*/


// binary search using recursion

/*
int binarysearchrecursive(vector <int>&v,int lo, int hi,int target){
    int mid = lo + (hi - lo) / 2;
    if(lo>hi) return -1;
    if (target == v[mid]) {
        return mid;
    } else if (target < v[mid]) {
        binarysearchrecursive(v,lo,mid-1,target);
    } else {
        binarysearchrecursive(v,mid+1,hi,target);
    }
}

int main() {
    vector<int> v;
    for (int i = 0; i < 7; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end()); // Sort the input array
    int target;
    cin >> target;
    cout << binarysearchrecursive(v,0,v.size()-1, target);
    return 0;
}
*/

// Q 1: find out the first occurance of target in an array.
// method 1 : itrative approach , TC=O(n)
// method 2 : binary search approach ,  TC=O(log n)

/*
int binarysearchfirstoccurance(vector<int> &v, int target) {
    int lo = 0;
    int hi = v.size() - 1;
    int ans=-1;
    while (lo <= hi) { 
        int mid = lo + (hi - lo) / 2;
        if (target == v[mid]) {
            ans=mid;
            hi=mid-1;
        } else if (target < v[mid]) {
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    return ans;
}

int main() {
    vector<int> v;
    for (int i = 0; i < 10; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end()); // Sort the input array
    int target;
    cin >> target;
    cout << binarysearchfirstoccurance(v, target);
    return 0;
}
*/

// Q 2:  find out the square root of given non negative X . given array is sorted.
//       rouend it off to the nearest floor integer value.
//   i/p=  x=11
//   o/p=  3
/*
int squareroot(int x){
    int lo=1;
    int hi=x;
    int ans=-1;
    
    while(lo<=hi){
        int mid =lo+(hi-lo)/2;
        if(mid*mid<=x){
            ans=mid;
            lo=mid+1;      
        }
        else{
            hi=mid-1;
        }
    }
    return ans;
}

int main(){
    cout<<squareroot(24);
return 0;
}
*/

// lecture 45:  problems solving on binary search algo


//  Q 1 , given array a (sorted) , find  first and last ocurrance of the given "target" , follow 0 based indexing
/*
int firstoccurance(int arr[],int target,int size){  
    int lo = 0;
    int hi = size-1;
    int ans=-1;
    while (lo <= hi) { 
        int mid = lo + (hi - lo) / 2;
        if (arr[mid] >= target) {
            ans=mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    return ans;
}
int lastoccurance(int arr[],int target,int size){  
    int lo = 0;
    int hi = size-1;
    int ans=-1;
    while (lo <= hi) { 
        int mid = lo + (hi - lo) / 2;
        if (arr[mid] > target) {
             ans=mid;
            hi = mid - 1;
        } else {
           
            lo = mid + 1;
        }
    }
    return ans-1;     // ans is minus 1 of first ele that grster than target ele.
}

int main() {
    int arr[]={1,2,3,3,3,5,11};
    int size=7;
    int target;
    cin >> target;
    int first=firstoccurance(arr, target, size);
    int result[2];

    if(result[first]!=target){
        result[0]=-1;
        result[1]=-1;
    }else{
        int last=lastoccurance(arr, target, size);
        result[0]=first;
        result[1]=last;
    }
    cout<<result[0]<<" , "<<result[1];

return 0;
}
*/


//  Q 2 :a rotated sorted array is given. find out the index of minimum element in the array.

/*
int min_ele_rotatedsortarr(int arr[], int lo,int hi){
    if(hi==lo) return arr[0];  //if array of size 1
    
    if(arr[lo]<arr[hi]){
        return lo;
    }

    
    while(lo<=hi){
    int mid=lo+(hi-lo)/2;
    

    if(arr[mid-1]>arr[mid]) return mid;
    if(arr[mid]>arr[mid+1]) return mid+1;
    
    if(arr[lo]<arr[mid]){
        lo=mid+1;
    } else{
        hi=mid-1;        
    }
    }return -1;
} 

int main(){
    int arr[]={3,4,5,1,2};
    int size=5;
    cout<<min_ele_rotatedsortarr(arr,0,size-1);
return 0;
}
*/

// Q 3: given rotated sorted array ,an interger target . return index of target if it is in the array.

//method 1 ; 3 times binary search 
/*
int min_ele_rotatedsort(int arr[], int lo,int hi){
    if(hi==lo) return arr[0];  //if array of size 1
    
    if(arr[lo]<arr[hi]){
        return lo;
    }

    
    while(lo<=hi){
    int mid=lo+(hi-lo)/2;
    

    if(arr[mid-1]>arr[mid]) return mid;
    if(arr[mid]>arr[mid+1]) return mid+1;
    
    if(arr[lo]<arr[mid]){
        lo=mid+1;
    } else{
        hi=mid-1;        
    }
    }return -1;
} 

int binarysearchrotatedsort(int arr[],int target,int size){
    int lo=0;
    int hi=size-1;
    
   int min=min_ele_rotatedsort(arr,lo,hi); 
    if(target>arr[min] ){
        while (lo <= min-1) { 
        int mid = lo + (hi - lo) / 2;
        if (target == arr[mid]) {
            return mid;
        } else if (target < arr[mid]) {
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    } }
        else{
        while(min<=hi){
            int mid = min + (hi - min) / 2;
            if (target == arr[mid]) {
                return mid;
            } else if (target < arr[mid]) {
                hi = mid - 1;
            } else {
                min = mid + 1;
            }    
    }

    }
}

int main(){
    int arr[]={3,4,5,6,7,8,1,2};
    int size=8;
    int target;
    cin >> target;
    cout<<binarysearchrotatedsort(arr,target,size);
return 0;
}
*/

// method 2 : in single binary search (effective way )

/*
int binarysearchsortedrotated(int arr[],int target,int size){
    int lo=0;
    int hi=size-1;
    while(lo<=hi){
        int mid = lo + (hi - lo) / 2;
        if(target==arr[mid]) return mid;
        if(arr[lo]<=arr[mid]){
            if(target <= arr[mid] && target>=arr[lo]){
                hi=mid-1;
            }else{
                lo=mid+1;
            }
        }else{
            if(target<=arr[hi] && target >=arr[mid]){
                lo=mid+1;
            }else{
                hi=mid-1;
            }
        }

    }

}
int main(){
    int arr[]={3,4,5,6,7,8,1,2};
    int size=8;
    int target;
    cin >> target;
    cout<<binarysearchsortedrotated(arr,target,size);
return 0;
}
*/

//  Q 4 : search element in rotated sorted array with duplicate elements,
//         return 1 if found, othervise return -1.

/*
int binarysearchsortedrotated(int arr[],int target,int size){
     // avg case  T C is O( log n ) .
    // worst case time complexity is O( n ) .
    
    int lo=0;
    int hi=size-1;
    if(target==arr[hi]) return 1;
    while(lo>=hi){
        if(arr[lo]==arr[hi]){
            lo++;
            hi--;
        }
    }
    while(lo<=hi){
        int mid = lo + (hi - lo) / 2;
        if(target==arr[mid]) return 1;
        if(arr[lo]<=arr[mid]){
            if(target <= arr[mid] && target>=arr[lo]){
                hi=mid-1;
            }else{
                lo=mid+1;
            }
        }else{
            if(target<=arr[hi] && target >=arr[mid]){
                lo=mid+1;
            }else{
                hi=mid-1;
            }
        }

    }
    return -1;
}
int main(){
    int arr[]={0,0,0,1,1,1,2,0,0,0};
    int size=10;
    int target;
    cin >> target;
    cout<<binarysearchsortedrotated(arr,target,size);
return 0;
}
*/


//   LECTURE 46 : BINARY SEARCH PROBLEMS 2

//  Q 1 : find out the peak element from a mountain array.
/*
int peak_in_mountain(vector<int>& v){
    int lo=0,hi=v.size()-1;
    int ans=-1;
    while(lo<=hi){
        int mid=lo+(hi-lo)/2;
        
        if(mid==0 || v[mid-1]<v[mid]){   //this mid==0 is for 0th index check 
            ans=max(ans,mid);
            lo=mid+1;
        }else{
            hi=mid-1;
        }
    }
    return ans;
}

int main(){
    vector<int>input;
    int n;
    cin>>n;
    while(n--){
        int x;
        cin>>x;
        input.push_back(x);
    }
    cout<<"peak ele at index  : "<<peak_in_mountain(input);
    return 0;
}
*/

// Q 2 : find out the  peak and return its index. array contains multiple peaks.
//       also consider the strictly greater than neighbour that is outside the array.

/*
int anyPeakInMountain(vector<int> &v ){
    int n=v.size();
    int lo=0,hi=n-1;
    int ans=-1;
    while(lo<=hi){
        int mid=lo+(hi-lo)/2;
        if(mid==0){
            if(v[mid]>v[mid+1]){
                return 0;
            }else{
                return 1;
            }
        }else if(mid==n-1){
            if(v[mid]>v[mid-1]){
                return n-1;
            }else{
                return n-2;
            }
        }else{
            if(v[mid]>v[mid-1] && v[mid]>v[mid+1]){
                return mid;
            }else if(v[mid]<v[mid-1]){
                hi=mid-1;
            }else{
                lo=mid+1;
            }
        }
    }

}

int main(){
    vector<int>input;
    int n;
    cin>>n;
    while(n--){
        int x;
        cin>>x;
        input.push_back(x);
    }
    cout<<"peak ele at index  : "<<anyPeakInMountain(input);
    return 0;
}
*/  

// Q 3 : given a 2d matrix of dimensions nXm. find target,  each row is sorted ,
//        last element of each row is less than the first elment of next row. 

/*
bool searchinmatrix(vector<vector<int>>&v,int target){
    int n=v.size();     //no. of rows
    int m=v[0].size();  //no. of columns
    int lo=0;
    int hi=n*m-1;

    while(lo<=hi){
        int mid=lo+(hi-lo)/2;
        int x=mid/m;
        int y=mid%m;
        if(v[x][y] == target) {
            return true;
        }else if(v[x][y] < target) {
            lo=mid+1;
        }else{
            hi=mid-1;
        }   
    }
    return false;
}

int main(){
    vector<vector< int >>v={{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    int target;
    cin>>target;
    cout<<searchinmatrix(v,target);
return 0;    
}

*/

//  Lecture 47 : binary problem solving 3

//  Q 1 : distribute chocolate boxes in students such that 
//       maximum no of chocolates allocated to a student is minimum.
//       each student should get a box . and box allocation is unique.

/*
bool candistchoco(int box[],int mid,int size, int s){
    int studentreq=1;
    int currSum=0;
    for(int i=0;i<size;i++){
        if(box[i]>mid) return false;
        if(currSum + box[i] > mid){
            studentreq++;
            currSum=box[i];
            if(studentreq>s) return false;
        }else{
            currSum+=box[i];
        }
    }
    return true;
}

int minPossibleNum(int box[],int size,int s){
    // search space 
    int lo=box[0];
    int hi=0;
    for(int i=0;i<size;i++){
        hi+=box[i];
    }
    int  ans=-1;
    while(lo<=hi){
        int mid=lo+(hi-lo)/2;
        if(candistchoco(box,mid,size,s)){
            ans=mid;
            hi=mid-1;
        }else{
            lo=mid+1;
        }
    }
    return ans; 
}

int main(){
    int box[]={12,34,67,90};  // no. of boxes == array size  // sorted in inc.
    int size=4;
    int noOfStudents=2;
    cout<< minPossibleNum(box,size,noOfStudents);
return 0;    
}
*/


//  Q 2 : build racing track for kids having "n" starting spots . m students is allowed to
//      enter in race at a time . choose starting spots such that minimum distance btw two students is maximum.  



// space = O(1)
// time  : O(n logn(xn-x1))
bool can_place_students(vector<int>&pos,int s,int mid){
   
    int studentreq=1;
    int lastplaced= pos[0];
    for(int i=0;i<pos.size();i++){
        if(pos[i]-lastplaced > mid ){
            studentreq++;   //student placing
            lastplaced=pos[i];
            if(studentreq == s) return true;

        }
    }
    return false;

}

int race(vector<int>&v,int s){
    int n=v.size();
    int lo= 1;
    int hi=n-1;
    int ans=-1;
    while(lo<=hi){
        int mid=lo+(hi-lo)/2;
        if(can_place_students(v,s,mid)){
            ans=mid;
            lo=mid+1;
        }else{
            hi=mid-1;
        }        
    }
    return ans;
}

int main() {
    vector<int>v={1,2,5,8,9};
    int students;
    cin>>students;
    cout<< race(v,students);
    return 0;
}