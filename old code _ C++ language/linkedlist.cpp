#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#include <climits>
#include <algorithm>
#include <string>
using namespace std;

// lecture  :  50
// linked list :  1st 

// insertion at head and tail , display linked list
class node{
    public:
    int val;
    node* next;
    node(int data){
        val=data;
        next=NULL;
    } 
};
void insertAtHead(node* &head,int val){
    node* newnode= new node(val);
    newnode->next=head;
    head=newnode;
}
void display(node* head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->val<<endl;
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}
void insertAtTail(node* &head,int val){
    node* new_node= new node(val);
    node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=new_node;
  //  new_node->next=NULL;
    
}

int main(){
    node* n = new node(1);
  //  cout<<n->val<<" "<<n->next <<endl;
    node* head=NULL;
    insertAtHead(head,4);
    display(head);
    insertAtHead(head,5);
    display(head);
    insertAtTail(head,9);
    display(head);
    insertAtTail(head,3);
    display(head);
    display(n);
return 0;

}

//  