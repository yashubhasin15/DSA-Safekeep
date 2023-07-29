#include<iostream>
using namespace std;

template <typename T>
class QueueUsingArray{
  T* data;
  int nextIndex;
  int firstIndex;
  int size;
  int capacity;

  public:
  QueueUsingArray(int length){
    capacity=length;
    data= new T[length];
    nextIndex=0;
    firstIndex=0;
    size= 0;
  }

  int getSize(){
    return size;
  }
  bool isEmpty(){
    return size==0;
  }
  void enqueue(T element){
    if(size==capacity){
      cout<<"Queue is full"<<endl;
      return;
    }
    data[nextIndex]=element;
    nextIndex=(nextIndex+1)%capacity;
    size++;
  }
  T dequeue(){
    if(isEmpty()){
      cout<<"Queue is empty"<<endl;
      return 0;
    }
    T ans= data[firstIndex];
    firstIndex=(firstIndex+1)%capacity;
    size--;
    return ans;

  }
  T front(){
    if(isEmpty()){
      cout<<"Queue is empty"<<endl;
      return 0;
    }
    return data[firstIndex];
  }

};

int main(){
  QueueUsingArray<int> q1(5);
  q1.enqueue(1);
  q1.enqueue(2);
  q1.enqueue(3);
  q1.enqueue(4);
  q1.enqueue(5);
  q1.enqueue(6);

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

  cout<<q1.dequeue()<<endl;
  cout<<q1.dequeue()<<endl;
  cout<<q1.dequeue()<<endl;

  return 0;
}