#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#include <climits>
#include <algorithm>
#include <string>


using namespace std;

// lecture : 48 : strings in one shot

// try this  1 : sort a string in increasing order

/*
// space O(26)
// time O(lengh of str)

string countSort(string str){
    vector<int > freq(26,0);
    
    //storing freq of every character
    for(int i=0;i<str.length();i++){
        int index=str[i]-'a';
        freq[index]++;
    }
    // creating our sorted string 
    int j=0;
    for(int i=0;i<26;i++){
        while(freq[i]--){
            str[j++]=i + 'a';
        }
    }
    return str;
}

int main(){
    string str;
    cin>> str;
    cout << countSort(str)<<endl;
return 0;    
}
*/

// try this 2 : check anagram 
/*
bool anagram(string s1,string s2 ){
    vector<int>freq(26,0);

    if(s1.length()!=s2.length()){
        return false;
    }
    for(int i=0;i<s1.length();i++){
        freq[s1[i]-'a']++;
        freq[s2[i]-'a']--;
    }
    for(int i=0;i<26;i++){
        if(freq[i]!=0){
            return false;
        }
    }return true;
}

int main(){
    string s1,s2;
    cin>>s1>>s2;
    if(anagram(s1,s2)){
        cout<< "yes";
    }else{
        cout<<"no";
    }

return 0;    
}

*/

// try this 3 : isomorphic strings
/*
bool isomorphic(string s1,string s2){
    vector<int>v1(128,-1);
    vector<int>v2(128,-1);

    if (s1.size() != s2.size())  return false;
    for (int i=0;i<s1.size();i++) {
        if(v1[s1[i]] != v2[s2[i]]) return false;
        v1[s1[i]]=v2[s2[i]]=i;
    }
    return true;
}

int main(){
    string s1,s2;
    cin>>s1>>s2;
    if(isomorphic(s1,s2)){
        cout<<"yes";

    }else{
        cout<<"no";
    }
return 0;}

*/

// try this 4 : find longest common string .
/*
string LCP(vector<string>v){
    sort(v.begin(),v.end());

    string s1=v[0];
    string s2=v[v.size()-1];
    int i=0,j=0;
    string ans="";
    while(i<s1.size() && j<s2.size()){
        if (s1[i]==s2[j]){
            ans+=s1[i];
            i++; j++;
        }else{
            return ans;
        }
    }
}

int main(){
    cout<<"Enter no. of strings : ";
    int n ;
    cin>>n;
    cout<<"enter strings: "<<endl;
    vector<string>v(n);
    for(int i=0;i<n;i++){ 
        cin>>v[i];
    }
    cout<<"longest common prefix: "<< LCP(v);
    return 0;
}

*/

// same question without using sort.
/*
string LCP(vector<string>v){
    string str=v[0];
    int ansL=str.size();
    
    for(int i=1;i<v.size();i++){
        int j=0;
        while (j<str.size() && j<v[i].size() && str[j]==v[i][j]){
            j++;
        }
        ansL=j;
    }
    string ans=str.substr(0,ansL);
    return ans;

}

int main(){
    cout<<"Enter no. of strings : ";
    int n ;
    cin>>n;
    cout<<"enter strings: "<<endl;
    vector<string>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    cout<<"longest common prefix: "<< LCP(v);
    return 0;
}
*/



// try this 5 : decode the string
/*
string decoder(string str){

    string result="";
    
    
    // for traversing the decoding 
    for (int i=0;i<str.length();i++){
        if(str[i] != ']'){
            result.push_back(str[i]);
        }else{
            string st="";
            
            while(!result.empty() && result.back()!='['){
                st.push_back(result.back());
                result.pop_back();
            }
            result.pop_back();
            reverse(st.begin(),st.end());
            string num;
            while(!result.empty() && result.back()>='0' && result.back() <='9'){
            num.push_back(result.back());
            result.pop_back();
            }
            reverse(num.begin(),num.end());
            int int_num = stoi(num);
            // inserting st in result int_num times 
            while(int_num){
                result+=st;
                int_num--;
            }
        }   

    }
    return result;
}

int main(){
    string str;
    cin>>str;
    cout<<decoder(str);
    return 0;
}
*/


// try this 6 : find consecutive longest ones , we can change k zeroes.

int longestOnes(string str,int k){
    int start=0;
    int end=0;
    int zeroes=0;
    int max_length=0;

    for(;end<str.length();end++){
        if (str[end] == '0'){
            zeroes++;
            
        }
        while(zeroes>k){
            if(str[start]=='0'){zeroes--;}
            start++;
        }
        max_length = max(max_length,end-start+1);
    }
    return max_length;
}

int main(){
    string str;
    cin>>str;
    int k;
    cin>>k;
    cout<<longestOnes(str,k);

return 0;    
}

