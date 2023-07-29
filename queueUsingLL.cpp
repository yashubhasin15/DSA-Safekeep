#include<iostream>
using namespace std;

template <typename T>
class Node{
  public:
    T data;
    Node<T>* next;

    Node(T data){
      this->data= data;
      next= NULL;
    }
};

template <typename T>
class QueueUsingLL{
  Node<T>* head;
  Node<T>* tail;
  int size;

  public:
  QueueUsingLL(int length){
    head= NULL;
    tail= NULL;
    size= 0;
  }

  int getSize(){
    return size;
  }
  bool isEmpty(){
    return size==0;
  }
  void enqueue(T element){
    Node<T>* newNode= new Node<T>(element);
    if(head==NULL){
      head= newNode;
      tail= newNode;
    }
    else{
      tail->next= newNode;
      tail=newNode;
    }
    size++;
  }
  T dequeue(){
    if(isEmpty()){
      cout<<"Queue is empty"<<endl;
      return 0;
    }
    T ans= head->data;
    Node<T>* temp= head;
    head=head->next;
    delete temp;
    size--;
    return ans;

  }
  T front(){
    if(isEmpty()){
      cout<<"Queue is empty"<<endl;
      return 0;
    }
    return head->data;
  }

};

int main(){
  QueueUsingLL<int> q1(5);
  q1.enqueue(1);
  q1.enqueue(2);
  q1.enqueue(3);
  q1.enqueue(4);
  q1.enqueue(5);

  cout<<q1.front()<<endl;
  cout<<q1.getSize()<<endl;

  cout<<q1.dequeue()<<endl;
  cout<<q1.dequeue()<<endl;

  q1.enqueue(6);
  cout<<q1.dequeue()<<endl;
  cout<<q1.dequeue()<<endl;
  cout<<q1.dequeue()<<endl;
  cout<<q1.dequeue()<<endl;
  cout<<q1.dequeue()<<endl;

  q1.enqueue(7);
  q1.enqueue(8);

  cout<<q1.front()<<endl;
  cout<<q1.getSize()<<endl;
  
  cout<<q1.dequeue()<<endl;
  cout<<q1.dequeue()<<endl;
  cout<<q1.dequeue()<<endl;

  return 0;
}