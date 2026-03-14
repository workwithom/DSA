#include<iostream>
#include<vector>

using namespace std;
int main()
{
    /*

int array[]={1,3,5,7,9} ; 

int size=sizeof(array)/sizeof(array[0]);
cout <<size<<endl;
int sum=0;

for(int i=0;i<size;i++){
 sum+=array[i];

}
cout<<sum<<endl;





/*
//for loop
for(int idx=0;idx<size;idx++)
{cout<<array[idx]<<endl;
}

//for each loop
for(int ele:array)
{cout<<ele<<endl;

}
//while loop

int index=0;
while(index<size)

{ cout<<array[index]<<endl;
 index++;

}


//input methods

char vowels[5];
int size=sizeof(vowels)/sizeof(vowels[0]);

//using for loop

/*

for(int index=0;index<size;index++){
 // cin>>vowels[index];
}
for(int index=0;index<size;index++){
//  cout<<vowels[index];
}
//using for each loop

for(char &ele:vowels)
{ cin>>ele;
}



int array[]={4,6,8,2,9,3};

int max=array[0];
for(int i=0;i<6;i++)
{
    if(array[i]>max){
     max=array[i];

    }
}
cout<<max<<endl;

//linear search 

int key;
cin>>key;

int ans=-1;


for(int i=0;i<6;i++){
    if(array[i]==key){
        ans=i;
        break;

    }

}
cout<<ans<<endl;


//array #2

vector<int> v;

//operations of vectors...
v.push_back(2);
v.push_back(3);
v.push_back(4);
v.push_back(5);
v.insert(v.begin(),1);
v.insert(v.end(),6);
v.pop_back();
v.erase(v.end()-2);
//v.erase (v.end()-2);



cout<<v.size()<<"\n";
cout<<v.capacity()<<endl;
//cout<<v.begin()<<endl;  ye print nhi hota...
cout<<v[3];

*/
vector<int>v;

//for loop

for(int i=0;i<5;i++)
{int element;
cout<<"enter elements:\n";
cin>>element;     //if size was declared then we can use cin>>v[i]; directly...
v.push_back(element);
}

for(int i=0;i<v.size();i++){
 //cout<<v[i]<<endl;
}




/*
//for each loop
for(int ele:v){
    cout<<ele;

}
int i=0;
while(i<v.size()){
    cout<<v[i++];
    


}
//Q1, code for last occarance of x in vector

int x,occ=-1;
cin>>x;

for(int i=0;i<v.size();i++){
    if(x==v[i])
     occ=i; 

}
cout<<"index is "<<occ;


//Q2,  count occarance of x;
int x,occ_count=0;
cout<<'entr x:';
cin>>x;

for(int i=0;i<v.size();i++){
    if(x==v[i])
     occ_count++;


}
cout<<"the count is "<<occ_count;



//Q4..even indices sum - odd indices sum

int x=0,y=0;


for(int i=0;i<v.size();i++){
    if(i%2==0)
     x+=v[i]; 
    else
     y+=v[i];

}
cout<<"diff b/w even idx sum - odd idx sum is "<<x-y;
*/

} 