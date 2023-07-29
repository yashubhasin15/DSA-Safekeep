#include <iostream>
using namespace std;

void mergeSortedArrays(int* arr,int start,int end){
  int mid= (start+end)/2;
  int* sortedArr=new int[start+end];
  int i=start,j=mid+1;
  int current=start;

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

  if(i>mid){
    while(j<=end){
      sortedArr[current]=arr[j];
      j++;
      current++;
    }
  }
  else{
    while(i<=mid){
      sortedArr[current]=arr[i];
      i++;
      current++;
    }
  }
  for(int i=start;i<=end;i++){
    arr[i]=sortedArr[i];
  }

}

void mergeSort(int* arr, int start,int end){
  if(start>=end){
    return;
  }
  int mid=(start+end)/2;
  mergeSort(arr,start,mid);
  mergeSort(arr, mid+1,end);
  mergeSortedArrays(arr,start,end);
}

void binarySearch(int*arr, int l, int x){
  int start=0;
  int end=l-1;

  while (start<=end){
    int mid=(start+end)/2;

    if(arr[mid]==x){
      cout<<arr[mid]<<" ";
      return;
    }
    else if(arr[mid]>x){
      end=mid-1;
    }
    else{
      start=mid+1;
    }
  }
}

void arrayIntersection(int* arr1,int* arr2, int n, int m){
  if(n<m){
    mergeSort(arr1,0,n-1);
    for(int i=0;i<m;i++){
      binarySearch(arr1,n,arr2[i]);
    }
  }
  else{
    mergeSort(arr2,0,m-1);
    for(int i=0;i<n;i++){
      binarySearch(arr2,m,arr1[i]);
    }
  }
}

int main(){
  int n,m;
  cin>>n>>m;
  int* arr1= new int[n];
  int* arr2= new int[m];
  for(int i=0;i<n;i++){
    cin>>arr1[i];
  }
  for(int i=0;i<m;i++){
    cin>>arr2[i];
  }
  arrayIntersection(arr1,arr2,n,m);
  return 0;
}

