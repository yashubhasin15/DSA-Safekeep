#include<iostream>
#include<climits>
using namespace std;

class StackUsingArray{
  private:
  int* data;
  int nextIndex;
  int capacity;

  public:
  StackUsingArray(int length){
    data= new int[length];
    nextIndex=0;
    capacity= length;
  }

  int size(){
    return nextIndex;
  }

  bool isEmpty(){
    return nextIndex==0;
  }

  void push(int element){
    if(nextIndex==capacity){
      cout<<"Stack is full"<<endl;
      return;
    }
    data[nextIndex++]=element;
  }

  int pop(){
    if(isEmpty()){
      cout<<"Stack is empty"<<endl;
      return INT_MIN;
    }
    nextIndex--;
    return data[nextIndex];
  }

  int top(){
    if(isEmpty()){
      cout<<"Stack is empty"<<endl;
      return INT_MIN;
    }
    return data[nextIndex-1];
  }

};

int main(){
  StackUsingArray s(4);
  s.push(10);
  s.push(20);
  s.push(30);
  s.push(40);
  s.push(50);

  cout<<s.isEmpty()<<endl;

  cout<<s.pop()<<endl;
  cout<<s.pop()<<endl;

  cout<<s.top()<<endl;

  cout<<s.pop()<<endl;

  cout<<s.size()<<endl;

  cout<<s.pop()<<endl;
  cout<<s.pop()<<endl;
  
  return 0;
}