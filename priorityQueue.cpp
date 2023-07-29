#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;

class PriorityQueue{
  vector<int> pq;

  public:
  
  int getSize(){
    return pq.size();
  }

  bool isEmpty(){
    return pq.size()==0;
  }

  int getMin(){//In min priority queue, minimum elements will be on 0th index
    if(isEmpty()){
      return 0;
    }
    return pq[0];
  }

  void insert(int element){
    pq.push_back(element);

    int childIndex= pq.size()-1;
    while(childIndex>0){
      int parentIndex= (childIndex-1)/2;

      if(pq[childIndex]<pq[parentIndex]){
        swap(pq[childIndex],pq[parentIndex]);
        childIndex=parentIndex;
      }
      else{
        break;
      }
    }
  }

  int removeMin(){
    if(isEmpty()){
      return 0;
    }

    int minElement= pq[0];//we have to return this value
    pq[0]=pq[pq.size()-1];
    pq.pop_back();
    
    int parentIndex=0;
    int leftChildIndex= 2*parentIndex+1;
    int rightChildIndex= 2*parentIndex+2;

    while(leftChildIndex < pq.size()){
      int minIndex= parentIndex;
      
      if(pq[leftChildIndex]<pq[minIndex]){
        minIndex= leftChildIndex;
      }
      if(rightChildIndex < pq.size() && pq[rightChildIndex]<pq[minIndex]){
        minIndex= rightChildIndex;
      }
      if(minIndex==parentIndex){
        break;
      }
      swap(pq[minIndex],pq[parentIndex]);
      parentIndex= minIndex;
      leftChildIndex= 2*parentIndex+1;
      rightChildIndex= 2*parentIndex+2;
    }
    return minElement;
  }

};

int main(){
  PriorityQueue pq;
  cout<<"min is: "<<pq.getMin()<<endl;
  pq.insert(3);
  pq.insert(8);
  pq.insert(20);
  pq.insert(1);
  cout<<"min is: "<<pq.getMin()<<endl;
  cout<<"size is: "<<pq.getSize()<<endl;
  cout<<"removed: "<<pq.removeMin()<<endl;
  cout<<"removed: "<<pq.removeMin()<<endl;
  cout<<"removed: "<<pq.removeMin()<<endl;
  cout<<"removed: "<<pq.removeMin()<<endl;
  cout<<"removed: "<<pq.removeMin()<<endl;

  return 0;
}