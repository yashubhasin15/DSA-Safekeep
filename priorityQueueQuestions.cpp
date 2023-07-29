#include<iostream>
#include<queue>
using namespace std;

// QUESTION 1
void KsortedArray(int* arr, int n, int k){
  // K sorted array means array in which each element needs to be shifted by atmost k-1 positions(left or right) to make the array sorted
  // In this question, we have to sort array in ascending order and thus we use the min priority queue
  priority_queue<int, vector<int>, greater<int> > pq;

  for(int i=0;i<k;i++){
    pq.push(arr[i]);
  }
  for(int i=0;i<n;i++){
    if(k+i<n){
      pq.push(arr[k+i]);
    }
    arr[i]= pq.top();
    pq.pop();
  }
}

// QUESTION 2
void kSmallestElements(int* arr, int n, int k){
  priority_queue<int> pq;
  for(int i=0;i<k;i++){
    pq.push(arr[i]);
  }
  for(int i=k;i<n;i++){
    if(pq.top()>arr[i]){
      pq.pop();
      pq.push(arr[i]);
    }
  }

  while(!pq.empty()){
    cout<<pq.top()<<" ";
    pq.pop();
  }

}

// QUESTION 3
bool checkMaxHeap(int* arr, int n){
  int lastParentIndex= (n-2)/2;
  for(int i=0;i<=lastParentIndex;i++){
    if(arr[i]<arr[2*i+1] || (2*i+2<n && arr[i]<arr[2*i+2])){
      return false;
    }
  }
  return true;
}

// QUESTION 4
typedef pair<int,pair<int,int>> ppi; //first is element and second is pair of array index and element index in that array

vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays){
  vector<int> ans;
	priority_queue<ppi, vector<ppi>,greater<ppi>> pq;

	for(int i=0;i<kArrays.size();i++){
    pq.push( { kArrays[i][0], {i, 0} } ); //by default, in priority queues of pairs, priority is dependent upon "first" of pair
	}

  while(!pq.empty()){
    ppi min= pq.top(); //this will give that pair whose first is minimum
    pq.pop();

    ans.push_back(min.first);
    int arrayIndex= min.second.first;
    int elementIndex= min.second.second;
    
    if(elementIndex+1 < kArrays[arrayIndex].size()){
      pq.push({kArrays[arrayIndex][elementIndex+1],{arrayIndex,elementIndex+1}});
    }
  }

  return ans;
}

// QUESTION 5
void runningMedian(int* arr, int n){
  priority_queue<int> maxHeap;
  priority_queue<int, vector<int>, greater<int>> minHeap;
  maxHeap.push(arr[0]);
  cout<<"Running Median: "<<arr[0]<<endl;
  for(int i=1;i<n;i++){
    if(arr[i]>maxHeap.top()){
      minHeap.push(arr[i]);
      if(minHeap.size()-maxHeap.size()>1){
        int temp=minHeap.top();
        minHeap.pop();
        maxHeap.push(temp);
      }
    }
    else{
      maxHeap.push(arr[i]);
      if(maxHeap.size()-minHeap.size()>1){
        int temp=maxHeap.top();
        maxHeap.pop();
        minHeap.push(temp);
      }
    }
    int median;
    if(maxHeap.size()==minHeap.size()){
      median= (maxHeap.top()+minHeap.top())/2;
    }
    else if(maxHeap.size()>minHeap.size()){
      median= maxHeap.top();
    }
    else{
      median= minHeap.top();
    }
    cout<<"Running Median: "<<median<<endl;
  }
}

// QUESTION 6
int timeRequiredToBuyTicket(int* arr, int n, int k){
  priority_queue<int> prioQue;
  queue<int> indexQue;
  for(int i=0;i<n;i++){
    prioQue.push(arr[i]);
    indexQue.push(i);
  }
  int time=0;
  while(!indexQue.empty()){
    if(arr[indexQue.front()]==prioQue.top()){
      if(indexQue.front()==k){
        return time;
      }
      indexQue.pop();
      prioQue.pop();
      time++;
    }
    else{
      int temp=indexQue.front();
      indexQue.pop();
      indexQue.push(temp);
    }
  }
  return time;
}


int main(){

  // QUESTION 1
  // int n,k;
  // cin>>n>>k;
  // int* arr=new int[n];
  // for(int i=0;i<n;i++){
  //   cin>>arr[i];
  // }
  // KsortedArray(arr,n,k);

  // for(int i=0;i<n;i++){
  //   cout<<arr[i]<<" ";
  // }

  // 7 3
  // 6 5 3 2 8 10 9 this is a k-sorted array with k=3

  // QUESTION 2
  // int n,k;
  // cin>>n>>k;
  // int* arr= new int[n];
  // for(int i=0;i<n;i++){
  //   cin>>arr[i];
  // }
  // kSmallestElements(arr,n,k);

  // QUESTION 3
  // int n;
  // cin>>n;
  // int* arr= new int[n];
  // for(int i=0;i<n;i++){
  //   cin>>arr[i];
  // }
  // cout<<checkMaxHeap(arr,n);

  //6 11 8 4 6 7 0  this will give true
  //7 8 4 4 2 1 3 6 this will give false

  // QUESTION 4
  // vector<vector<int> > arr{ {2,6,12},{1,9},{23,34,90,2000} };
  // vector<int> output = mergeKSortedArrays(arr);

  // cout << "Merged array is " << endl;
  // for (auto x : output)
  //     cout << x << " ";

  // QUESTION 5
  // int n;
  // cin>>n;
  // int* arr= new int[n];
  // for(int i=0;i<n;i++){
  //   cin>>arr[i];
  // }
  // runningMedian(arr,n);

  // QUESTION 6
  int n,index; //index->index of the person for which we need to calculate time
  cin>>n>>index;
  int* arr= new int[n];
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  cout<<timeRequiredToBuyTicket(arr,n,index)<<endl;

  return 0;
}