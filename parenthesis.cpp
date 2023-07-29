#include<iostream>
#include<string>
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

template <typename T>
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
      return 0;
    }
    return head->data;
  }

};

bool parenthesis(string a){
  StackUsingLL<char> stk;
  for(int i=0;a[i]!='\0';i++){
    if(a[i]=='(' || a[i]=='[' || a[i]=='{'){
      stk.push(a[i]);
    }
    else if(a[i]==')' || a[i]==']' || a[i]=='}'){
      if(stk.isEmpty()){
        return false;
      }
      else if(a[i]==')' && stk.top()=='('){
      stk.pop();
      }
      else if(a[i]==']' && stk.top()=='['){
        stk.pop();
      }
      else if(a[i]=='}' && stk.top()=='{'){
        stk.pop();
      }
      else{
        return false;
      }
    }
  }
  return stk.isEmpty();
}

int main(){
  string a;
  cin>>a;
  cout<<(parenthesis(a)?"true":"false");
  
  return 0;
}