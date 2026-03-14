#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

#include<climits>
using namespace std;

// lecture 21 time and space complexity 

int sum_in_range(int x,int y){
    int result=0;
    for(int i=x;i<=y;i++){     // this loop has time compx of O(n)
        result+=i;

    }
    return result;
}

int sum_in_range_opt(int x, int y){  
    int n=y-x+1;   // this AP has time compx of O(constant)
    int a=x;
    int d=1;

    int result=(n*(2*a+(n-1)*d))/2;
return result;
}
int main(){
    int x=2;
    int y=6;
    cout<< sum_in_range_opt(x,y);
    
return 0;
 
}