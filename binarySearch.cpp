#include <iostream>
using namespace std;

int binarysearch(int* arr, int n, int i){
  int start=0, end=n-1;

  while (start<=end){
    int mid=(start+end)/2;

    if(arr[mid]==i){
      return mid;
    }

    else if(arr[mid]>i){
      end=mid-1;
    }

    else{
      start=mid+1;
    }
  }

  return -1;
}

int main(){
  int a,n;
  cin>>a>>n;
  int arr[n];

  for(int i=0;i<n;i++){
    cin>>arr[i];
  }

  cout<<"Index of "<<a<<" is "<<binarysearch(arr,n,a);
  return 0;
}

