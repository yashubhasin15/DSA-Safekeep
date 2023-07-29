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

Node* mergeTwoSortedLL(Node* head1 , Node* head2){
  Node *finalHead=NULL, *finalTail= NULL;
  if(head1==NULL){
    return head2;
  }
  if(head2==NULL){
    return head1;
  }

  if(head1->data < head2->data){
    finalHead= head1;
    finalTail=finalHead;
    head1=head1->next;
  }
  else{
    finalHead= head2;
    finalTail=finalHead;
    head2=head2->next;
  }

  while(head1!=NULL && head2!=NULL){
    if(head1->data < head2->data){
      finalTail->next= head1;
      finalTail= head1;
      head1=head1->next;
    }
    else{
      finalTail->next= head2;
      finalTail= head2;
      head2= head2->next;
    }
  }
  if(head1==NULL){
    finalTail->next=head2;
  }
  else{
    finalTail->next= head1;
  }

  return finalHead;

}

Node* midNode(Node* head){
  if(head==NULL){
    return NULL;
  }
  Node* slow= head; 
  Node* fast= head;
  while(fast->next!=NULL && fast->next->next!=NULL){
    slow=slow->next;
    fast= fast->next->next;
  }
  return slow;
}

Node* mergeSortLL(Node* head){
  if(head==NULL || head->next==NULL){
    return head;
  }
  Node* mid= midNode(head);
  Node* half1= head;
  Node* half2= mid->next;
  mid->next= NULL;

  half1= mergeSortLL(half1);
  half2= mergeSortLL(half2);
  Node* finalHead= mergeTwoSortedLL(half1,half2);

  return finalHead;
}

int main(){
  Node* head= takeInput();
  head= mergeSortLL(head);
  printLL(head);
  
  return 0;
}