#include<iostream>
#include<climits>
using namespace std;

class StackUsingArray{
  private:
  int* data;
  int nextIndex;
  int capacity;

  public:
  StackUsingArray(){
    data= new int[5];
    nextIndex=0;
    capacity= 5;
  }

  int size(){
    return nextIndex;
  }

  bool isEmpty(){
    return nextIndex==0;
  }

  void push(int element){
    if(nextIndex==capacity){
      int* newData= new int[2*capacity];
      for(int i=0;i<capacity;i++){
        newData[i]=data[i];
      }
      capacity*=2;
      delete [] data;
      data= newData;
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
  StackUsingArray s;
  int input;
  cin>>input;
  while(input!=-1){
    s.push(input);
    cin>>input;
  }

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