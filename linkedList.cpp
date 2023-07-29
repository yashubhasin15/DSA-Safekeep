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

  while(data != -1){
    Node* newNode= new Node(data);
    if(head==NULL){
      head= newNode;
      tail=head;
    }
    else{
      tail->next= newNode;
      tail= tail->next;
    }
    cin>>data;
  }

  return head;
}

void printLL(Node* head){
  while(head != NULL){
    cout<<head->data<<" ";
    head= head->next;
  }
  cout<<endl;
}

int lengthLL(Node* head){
  int length=0;
  while(head!=NULL){
    head=head->next;
    length++;
  }
  return length;
}

void midpoint(Node* head){
  Node* slow= head; 
  Node* fast= head;
  if(head!=NULL){
    while(fast->next!=NULL && fast->next->next!=NULL){
      slow=slow->next;
      fast= fast->next->next;
    }
    cout<<slow->data<<endl;
  }

}

Node* insertNode(Node* head,int index, int data){
  Node* newNode= new Node(data);
  if(index==0){
    newNode->next= head;
    head=newNode;
    return head;
  }

  Node* temp= head;
  for(int i=0;i<index-1 && temp!=NULL;i++){
    temp=temp->next;
  }
  if(temp!=NULL){
    newNode->next=temp->next;
    temp->next=newNode;
  }

  return head;
}

Node* insertNodeRec(Node* head, int index, int data){
  if(index==0){
    Node* newNode= new Node(data);
    newNode->next=head;
    head= newNode;
    return head;
  }
  if(head==NULL){
    return head;
  }
  Node* newHead= insertNodeRec(head->next,index-1,data);
  head->next= newHead;
  return head;
}

Node* deleteNode(Node* head, int index){
  if(index==0){
    Node* a= head;
    head= head->next;
    delete a;
    return head;
  }

  Node* temp= head;
  for(int i=0;i<index-1 && temp->next!=NULL;i++){
    temp=temp->next;
  }
  if(temp->next!=NULL){
    Node* a= temp->next;
    temp->next= a->next;
    delete a;
  }
  
  return head;
}

Node* deleteNodeRec(Node* head, int index){
  if(index==0){
    Node* a= head;
    head= head->next;
    delete a;
    return head;
  }
  if(head->next==NULL){
    return head;
  }

  Node* newHead= deleteNodeRec(head->next,index-1);
  head->next= newHead;
  return head;
}

int main(){
  Node* head= takeInput();

  int x=-1;
  while(x!=0){
    cout<<"Press 1 to print linked list"<<endl;
    cout<<"Press 2 to print length of linked list"<<endl;
    cout<<"Press 3 to delete node"<<endl;
    cout<<"Press 4 to insert node"<<endl;
    cout<<"Press 5 to print midpoint"<<endl;
    cout<<"Press 0 to end"<<endl;

    cin>>x;

    switch(x) {
    case 0:
      break;
    case 1:
      printLL(head);
      break;
    case 2:
      cout<<lengthLL(head)<<endl;
      break;
    case 3:
      int j;
      cin>>j;
      head=deleteNode(head,j);
      // head= deleteNodeRec(head,j);
      break;
    case 4:
      int data,i;
      cin>>data>>i;
      head= insertNode(head,i,data);
      // head=insertNodeRec(head,i,data);
      break;
    case 5:
      midpoint(head);
      break;
    default:
      cout<<"Enter a valid number"<<endl;
    }
  }

  return 0;
}