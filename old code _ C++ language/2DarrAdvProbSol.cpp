#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<climits>
using namespace std;

// lecture 19: advance problem solving 1

// Q 1... a boolean 2D array given is sorted, 
//      find out the row no. which have maximum no. of ones . 
/*
int maximumonesrow(vector<vector<int>> v){
    int maxonesrow=-1;
    int maxones=INT_MIN;
    int columns=v[0].size();
    for(int i=0;i<v.size();i++){
        for(int j=0;j<v[i].size();j++){

            if(v[i][j]==1){
                int numberofones=columns-j;
                if(numberofones>maxones){
                    maxones=numberofones;
                    maxonesrow=i;
                }
                break;
            }
        }
    }
    return maxonesrow;
}

int main(){
    int n=3,m=4;
    vector<vector<int>>v(n,vector<int>(m));
    v={{0,0,1,1},{0,0,0,1},{0,1,1,1}};

    int res=maximumonesrow(v);
    cout<<res<<endl;
    return 0;
}


// better way
//  find row with leftmost one.
//   find left most column number which has 1 , then check for left of that column only.
int leftmostonerow(vector<vector<int>> v){
    int maxonesrow=-1;
    int leftmostone=-1;
    int j=v[0].size()-1;
    // finding left most one at 0th row
    while(j>=0 && v[0][j]==1){
        j--;
        leftmostone=j;
        maxonesrow=0;
    }
// check in rest of the rows if we can find a one left to the leftmostone         
    for(int i=0;i<v.size();i++){
        while (j>=0 && v[i][j]==1){
                leftmostone=j;
                j--;
                maxonesrow=i;
            }
        }
    
    return maxonesrow;
}

int main(){
    int n=3,m=4;
    vector<vector<int>>v(n,vector<int>(m));
    v={{0,0,1,1},{0,0,0,1},{0,1,1,1}};

    int res=leftmostonerow(v);
    cout<<res<<endl;
    return 0;
}
*/

//Q2... rotate a 2D vector by 90 degree.
//  for this, we have to transpose it and then reverse every vector (row).
/*
void rotate90(vector<vector<int>>&v){
    // transpose
    int n=v.size();
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){ // j<i ,only lower digonal elements should be swap.
         //   v[i][j]=v[j][i];  this is general tranposing
            swap(v[i][j],v[j][i]);
        }
    }
    // reverse each row vector
    for (int i=0;i<n;i++){
        reverse(v[i].begin(),v[i].end());
    }
return;}

int main(){
    int n=3;

    vector<vector<int>>v(n,vector<int>(n));
    v={{1,2,3},{4,5,6},{7,8,9}};
    rotate90(v);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<v[i][j]<<" ";

        }
        cout<<endl;
    }
    return 0;
}*/


// lecture 20: advance problem solving 2

// spiral matrix
// Q1... given an n x m matrix 'a' , return all elements of a matrix in spiral order
/*
void spiralmatrix(vector<vector<int>> & matrix){
    int direction=0;
    int left=0;
    int right=matrix[0].size()-1;
    int top=0;
    int bottom=matrix.size()-1;

    while(left<=right && top<=bottom){
        // for left to right print
        if(direction==0){ 
            for(int i=left;i<=right;i++){
                cout<<matrix[top][i]<<" ";
            }
            top++;
        }
        //for top to bottom print
        else if(direction==1){
            for(int i=top;i<=bottom;i++){
                cout<<matrix[i][right]<<" ";
            }
            right--;
        }
        //for right  to left print
        else if(direction==2){
            for(int i=right;i>=left;i--){
                cout<<matrix[bottom][i]<<" ";
            }
            bottom--;
        }
        // for bottom to top print
        else {
            for(int i=bottom;i>=top;i--){
                cout<<matrix[i][left]<<" ";
            }
            left++;
        }
        direction= (direction+1)%4;
    }
}


int main(){
    int n=3,m=4;
    vector<vector<int>> matrix(n,vector<int>(m));
    matrix={{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    spiralmatrix(matrix);

return 0;

}


// Q.2 .. . got input n , generate a n x n matrix filled with elements from 1 to n^2 in spiral order.

vector<vector<int>> spiralmatrixprint(int n){
    vector<vector<int>>ans(n,vector<int>(n));
    int left=0;
    int right=ans.size()-1;
    int top=0;
    int bottom=ans.size()-1;
    int num=1;

    int direction=0;

    while(left<=right && top<=bottom){
        if (direction==0){
            for(int i=left;i<=right;i++){
                ans[top][i]=num++;
            }
            top++;
        }
        else if(direction==1){
            for (int i=top;i<=bottom;i++){
                ans[i][right]=num++;
            }
            right--;
        }
        else if(direction==2){
            for (int i=right;i>=left;i--){
                ans[bottom][i]=num++;
            }
            bottom--;
        }
        else{
            for(int i=bottom;i>=top;i--){
                ans[i][left]=num++;
            }
            left++;
        }
        direction=(direction+1)%4;

    }   
    return ans;

}


int main() {
    int n;
    cin>>n;
    vector<vector<int>>matrix(n,vector<int>(n));
    matrix=spiralmatrixprint(n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<matrix[i][j]<<"  ";

        }
        cout<<endl;
    }




    return 0;
}

*/


// lecture 21 : advance array problem solving 3

// question : given a matrix "a" of dimension N x M and 2 coordinates l1,r1 and l2,r2.
//             return the sum of rectangle from l1,r1 to l2,r2.

// input vector , and (1,1) to (2,2)
//  1  2  3  4  
//  5  6  7  8
//  9  10 11 12    output : sum = 34

int prifix_sum(vector<vector<int>>&a,int l1,int r1,int l2,int r2){
    int sum=0;    
    //row wise prifix sum
    for(int i=0;i<a.size();i++){
        for(int j=1;j<a[0].size();j++){
            a[i][j]+=a[i][j-1];
        }
    }
    //coloumn wise prifix sum
    for(int i=1;i<a.size();i++){
        for(int j=0;j<a[0].size();j++){
            a[i][j]+=a[i-1][j];
        }
    }

    for(int i=0;i<a.size();i++){
        for(int j=0;j<a[0].size();j++){
            cout<<a[i][j]<<"  ";
        }
        cout<<endl;

    }
    //desierd sum
    int top_sum=0;
    int left_sum=0;
    int topleft_sum=0;
    if(r1!=0) left_sum=a[l2][r1-1];

    if(l1!=0) top_sum=a[l1-1][r2];

    if (l1!=0 && r1!=0) topleft_sum=a[l1-1][r1-1];
    sum=a[l2][r2]-top_sum-left_sum+topleft_sum;

    return sum;
}

int main(){
    int n,m,l1,r1,l2,r2;
    cin>>n>>m>>l1>>r1>>l2>>r2;
    vector<vector<int>>matrix(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            cin>>matrix[i][j];        
        }
    }
    for(int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            cout<<matrix[i][j]<<"  ";
        }
        cout<<endl;   
    }
    int sum = prifix_sum(matrix,l1,r1,l2,r2);
    cout<<"sum is : "<<sum;

return 0;
}












