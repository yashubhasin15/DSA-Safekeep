#include<iostream>
#include<climits>
using namespace std;

template <typename T>
class Node{
  public:
  T data;
  Node<T> *next;

  Node(T data){
    this->data= data;
    this->next= NULL;
  }
};

template<typename T>
class StackUsingLL{
  private:
  Node<T>* head;
  int length;

  public:
  StackUsingLL(){
    head= NULL;
    length= 0;
  }

  int size(){
    return length;
  }

  bool isEmpty(){
    return length==0;
  }

  void push(T element){
    Node<T>* newNode= new Node<T>(element);
    newNode->next=head;
    head= newNode;
    length++;

  }

  T pop(){
    if(isEmpty()){
      cout<<"Stack is empty"<<endl;
      return 0;
    }
    T ans= head->data;
    Node<T>* temp= head;
    head= head->next;
    delete temp;
    length--;
    return ans;
  }

  T top(){
    if(isEmpty()){
      cout<<"Stack is empty"<<endl;
      return 0;
    }
    return head->data;
  }

};

int main(){
  //for int
  StackUsingLL<int> s1;
  s1.push(10);
  s1.push(20);
  s1.push(30);
  s1.push(40);

  cout<<s1.isEmpty()<<endl;

  cout<<s1.pop()<<endl;
  cout<<s1.pop()<<endl;

  cout<<s1.top()<<endl;

  cout<<s1.pop()<<endl;

  cout<<s1.size()<<endl;

  cout<<s1.pop()<<endl;
  cout<<s1.pop()<<endl;


  cout<<endl;

  // for char
  StackUsingLL<char> s2;
  s2.push('c');
  s2.push('?');
  s2.push('4');
  s2.push(121);
  s2.push(30);

  cout<<s2.isEmpty()<<endl;

  cout<<s2.pop()<<endl;
  cout<<s2.pop()<<endl;

  cout<<s2.top()<<endl;

  cout<<s2.pop()<<endl;

  cout<<s2.size()<<endl;

  cout<<s2.pop()<<endl;
  cout<<s2.pop()<<endl;
  cout<<s2.pop()<<endl;
  
  return 0;
}