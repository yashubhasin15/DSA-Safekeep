#include <iostream>
using namespace std;

void mergeSortedArrays(int* arr,int start,int mid,int end){
  int* sortedArr=new int[end-start+1];
  int i=start,j=mid+1;
  int current=0;

  while(i<=mid && j<=end){
    if(arr[i]<=arr[j]){
      sortedArr[current]=arr[i];
      i++;
    }
    else{
      sortedArr[current]=arr[j];
      j++;
    }
    current++;
  }
  while(j<=end){
    sortedArr[current]=arr[j];
    j++;
    current++;
  }
  while(i<=mid){
    sortedArr[current]=arr[i];
    i++;
    current++;
  }
  for(int i=start;i<=end;i++){
    arr[i]=sortedArr[i-start];
  }
}

void mergeSort(int* arr,int start,int end){
  if(start>=end){
    return;
  }
  int mid=(start+end)/2;
  mergeSort(arr,start, mid);
  mergeSort(arr,mid+1,end);
  mergeSortedArrays(arr,start,mid,end);
}

int main(){
  int n;
  cin>>n;
  int* arr= new int[n];
  for (int i=0;i<n;i++){
    cin>>arr[i];
  }
  mergeSort(arr,0,n-1);
  for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
  }
  return 0;
}

