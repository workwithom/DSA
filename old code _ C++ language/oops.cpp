#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#include <climits>
#include <algorithm>
#include <string>

using namespace std;
// :  access modifiers 

/*
class teacher{
private:
    double salary;    
public:
    string name;
    int age;
    string dept;
    
    void changeDept(string dept){
        this->dept=dept;
    }
    void setSalary(double sal){     //setter
        salary=sal;
    }
    double getSalary(){             //getter
        return salary;
    }

};

int main () {
    teacher p1;
    p1.name="rahul";
    p1.age= 23;
    p1.dept="CSE";
    p1.setSalary(225000);
   // p1.changeDept("CIVIL");
    cout<<p1.name<<p1.age<<p1.dept<<p1.getSalary();
    

    return 0;
}

*/
 

//  : constrctors and destructors, shallow and deep copy

/*
class parent{
public:
    string name;
    
    int* ageptr;
   // parent(){
   //     cout<<"i'm nonparamet constructor \n";
   //     name="raj";
   //     age=45;
   // }    
    parent(string n,int a){
    cout<<"i'm paramet constructor \n";
    name=n;
    ageptr= new int;
    *ageptr=a;}
    void getInfo(){
        cout << name<<endl;
        cout<< *(ageptr)<<endl;
    }

    //copy constructor
    parent (parent &orgObj){
        this->name=orgObj.name;
        ageptr= new int;
        *ageptr=*orgObj.ageptr;
    }

    //destructor
    ~parent(){
        cout<< "im destructor";
    }
};



int main(){
    parent p1("rahul",30);  
    p1.getInfo();
  //  cout<<p1.name<<*(p1.ageptr);
    parent p2(p1);
    *(p2.ageptr)=45;
    p2.getInfo();
    p1.getInfo();
  //  cout<<p2.name<<*(p2.ageptr);
    

}

*/
// abstract class
class shape{
    virtual void draw()=0;  //pure virtual function
};
//inheritance



class parent{
private:
    double salary;
public:
    string name;
    int age;

};
class student :public parent{
public:
    int roll_no;

};
class gradStudent : public student{
public:
    string workarea;
};

int main(){
    gradStudent s1;
    s1.name="ramu";
    s1.age=23;
    s1.roll_no=245;
    s1.workarea="Cse";
    cout<<s1.name<<endl;
    cout<<s1.age<<endl;
    cout<<s1.roll_no<<endl;
}


// static keyword/variable =>  static int x=2;    one time run only
// static object =>  static parent p1 ; 













































