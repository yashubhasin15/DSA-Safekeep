#include<iostream>
#include<queue>// priority queue is also included in the queue library
using namespace std;

int main(){
  priority_queue<int> pq; //this queue is max priority queue i.e. max element is at pq[0]
  pq.push(69);
  pq.push(876);
  pq.push(6);
  pq.push(9);
  pq.push(639);
  pq.push(24);
  pq.push(23);

  cout<<"Size: "<<pq.size()<<endl;

  while(!pq.empty()){
    cout<<pq.top()<<endl; //this will print max element
    pq.pop();
  }

  return 0;
}