#include<iostream>
using namespace std;

class Node{
  public:
  int data;
  Node* next;

  Node(int data){
    this->data= data;
    this->next= NULL;
  }
};

Node* takeInput(){
  int data;
  cin>>data;
  Node* head= NULL;
  Node* tail= NULL;
  while(data!=-1){
    Node* newNode= new Node(data);
    if(head==NULL){
      head= newNode;
      tail=newNode;
    }
    else{
      tail->next= newNode;
      tail=newNode;
    }
    cin>>data;
  }
  return head;
}

void printLL(Node* head){
  while(head!=NULL){
    cout<<head->data<<" ";
    head=head->next;
  }
  cout<<endl;
}

Node* reverseLL(Node* head){
  if(head==NULL || head->next==NULL){
    return head;
  }
  Node* newHead= reverseLL(head->next);
  //answer of O(n) complexity
  head->next->next= head;
  head->next=NULL;

  //answer of O(n2) complexity
  // Node* temp= newHead;
  // while(temp->next!=NULL){
  //   temp=temp->next;
  // }
  // temp->next= head;
  // head->next=NULL;
  
  return newHead;

}

Node* reverseLLiterative(Node* head){
    Node* prev= NULL;
    Node* next= NULL;
    while(head!=NULL){
        next= head->next;
        head->next= prev;
        prev= head;
        head= next;
    }
    return prev;
}

int main(){
  Node* head= takeInput();
  head= reverseLL(head);
//   head= reverseLLiterative(head);
  printLL(head);
  
  return 0;
}