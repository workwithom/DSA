#include<iostream>
using namespace std;

// call by reference
/*
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
    
}

int main(){
    int x,y;
    cin>>x>>y;
    int *p1=&x;
    int *p2=&y;

    swap(p1,p2);
    cout<<x<<"  "<<y;

    return 0;

}
*/
/*
void findfirstandlastindex(string s,char ch, int *first,int *last){
    for(int i=0;i<s.size();i++){
        if(s[i]==ch){
            *first=i;
            break;
        }
    }
    for (int i=s.size()-1;i>=0;i--){
        if(s[i]==ch){
            *last=i;
            break;
        }
    }

    }

int main(){
    string s ="aaabac";
    char ch='a';
    int first=-1;
    int last=-1;
    int *p1=&first;
    int *p2=&last;

    findfirstandlastindex(s,ch,p1,p2);
    cout<<*p1<<" "<<*p2;
    return 0;

}
*/

//arrays as pointers :)
/*
void process(int *arr,int n){
    for(int i=0;i<n;i++){
        cout<<*(arr+i)<<"  ";

    }
    *(arr+2)=33;
}
int main(){
    int arr[3]={12,13,14};
           //here arr acts as a pointer who point 0th index address;
    cout<<" "<<*(arr+0)<<" ";
     cout<<" "<<*(arr+1)<<" ";
     cout<<" "<<*(arr+2)<<" ";
      cout<<" "<<*(arr+3)<<" \n ";
    process(arr,3);  
     cout<<" "<<*(arr+2)<<" ";
}
*/
int main(){
   int arr[5]={1,2,3,4,5};
   int (*p)[5]=&arr;

   cout<<p<<" "<<arr<<" "<<*p<<" "<<*arr; 
}



