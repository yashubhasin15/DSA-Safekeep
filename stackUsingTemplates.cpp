#include<iostream>
#include<climits>
using namespace std;

template <typename T>
class StackUsingArray{
  private:
  T* data;
  int nextIndex;
  int capacity;

  public:
  StackUsingArray(){
    data= new T[5];
    nextIndex=0;
    capacity= 5;
  }

  int size(){
    return nextIndex;
  }

  bool isEmpty(){
    return nextIndex==0;
  }

  void push(T element){
    if(nextIndex==capacity){
      T* newData= new T[2*capacity];
      for(int i=0;i<capacity;i++){
        newData[i]=data[i];
      }
      capacity*=2;
      delete [] data;
      data= newData;
    }
    data[nextIndex++]=element;
  }

  T pop(){
    if(isEmpty()){
      cout<<"Stack is empty"<<endl;
      return 0;
    }
    nextIndex--;
    return data[nextIndex];
  }

  T top(){
    if(isEmpty()){
      cout<<"Stack is empty"<<endl;
      return 0;
    }
    return data[nextIndex-1];
  }

};

int main(){
  //for int
  StackUsingArray<int> s1;
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

  //for char
  StackUsingArray<char> s2;
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