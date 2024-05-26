//lonked list is a dynaimic data structure it can grow and shrink in run time which prevents no memory wasteage
//insertion and tranversal and deletion along linked list

#include<bits/stdc++.h>
using namespace std;

  class Node{
   
   public:
   int data;
   Node* next;


//contructor
   Node(int data){
      this-> data= data;
      this -> next= NULL;
   }


   //destructure
   ~Node(){
    int value= this->data;
if(this->next!=NULL){
   delete next;
   this->next=NULL;

}   
cout<<"Memory is free for node with data "<<value<<endl;
}
};
  void InsertAtHead(Node* &head,int d){

    //new node
    Node* temp= new Node(d);
    temp->next= head;
    head= temp;

  }
  void InsertAtTail(Node* &tail,int d){
    Node* temp= new Node(d);
    tail->next=temp;
    tail=tail->next;
  }

  void InsertAtPosition(Node* &tail,Node* &head,int position,int d){

    if(position==1){
        InsertAtHead(head,d);
        return; 
    }
   Node* temp=head;
   int count=1;

   while(count<position-1){
    temp=temp->next;
    count++;

   }

   //insertingatast
   if(temp->next==NULL){
    InsertAtTail(tail,d);
    return;
   }
   Node* insert= new Node(d);
 insert->next= temp->next;
 temp->next= insert;


  }

  void deletenode(int position,Node* &head){
    if(position==1){
        Node* temp=head;
       head=head->next;

    }
    else{
          //deleting any middle or last node
          Node * curr=head;
          Node * prev=NULL;

          int cnt=1;
          while(cnt<=position){
        prev=curr;
        curr=curr->next;
        cnt++;
    }
    prev->next=curr->next;
    curr->next=NULL;\
    
    delete curr;
  }};

  


//print the linked list
  void print(Node* &head){
     Node * temp= head;
     //if head is null then return
     while(temp!=NULL){
        cout<<temp->data<<endl;
        temp=temp->next;

     }
     cout<<endl;
  }

int main(){

    Node *node1= new Node(10);
    Node* head=node1;
    Node* tail=node1;
    InsertAtHead(head,12);
    print(head);
    InsertAtTail(tail,15);
    print(head);
    InsertAtPosition(tail,head,1,13);
    print(head);
     deletenode(1,head);
     print(head);



    return 0;
}

