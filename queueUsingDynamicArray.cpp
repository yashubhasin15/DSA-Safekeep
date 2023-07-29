#include<iostream>
using namespace std;

template <typename T>
class QueueUsingDynamicArray{
  T* data;
  int nextIndex;
  int firstIndex;
  int size;
  int capacity;

  public:
  QueueUsingDynamicArray(){
    capacity=5;
    data= new T[5];
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
      T* newQueue= new T[2*capacity];
      int j=0;
      for(int i=firstIndex;i<capacity;i++){
          newQueue[j]= data[i];
          j++;
      }
      for(int i=0;i<firstIndex;i++){
          newQueue[j]= data[i];
          j++;
      }
      delete [] data;
      data= newQueue;
      firstIndex=0;
      nextIndex=capacity;
      capacity*=2;
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
  QueueUsingDynamicArray<int> q1;
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