#include <iostream>
using namespace std;

void mergeTwoSortedArrays(int* arr1, int* arr2, int n1, int n2){
  int arr[n1+n2];

  int i=0,j=0;
  int current=0;
  while(i<n1 && j<n2){
    if(arr1[i]<=arr2[j]){
      arr[current]=arr1[i];
      i++;
    }
    else{
      arr[current]=arr2[j];
      j++;
    }
    current++;
  }

  if(i==n1){
    while(j<n2){
      arr[current]=arr2[j];
      j++;
      current++;
    }
  }
  else{
    while(i<n1){
      arr[current]=arr1[i];
      i++;
      current++;
    }
  }

  for(int k=0;k<n1+n2;k++){
    cout<<arr[k]<<" ";
  }
}

int main(){
  int n1,n2;

  cout<<"enter size of first array: ";
  cin>>n1;
  int arr1[n1];
  cout<<"enter elements of first array: ";
  for(int i=0;i<n1;i++){
    cin>>arr1[i];
  }

  cout<<"enter size of second array: ";
  cin>>n2;
  int arr2[n2];
  cout<<"enter elements of second array: ";
  for(int i=0;i<n2;i++){
    cin>>arr2[i];
  }

  mergeTwoSortedArrays(arr1,arr2,n1,n2);

  return 0;
}

