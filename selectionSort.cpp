#include <iostream>
using namespace std;

void selectionSort(int* arr, int n){
  for (int start=0; start<n-1; start++){
    int min_index=start;

    for(int i=start; i<n; i++){
      if(arr[i]<arr[min_index]){
        min_index=i;
      }
    }

    int temp=arr[start];
    arr[start]=arr[min_index];
    arr[min_index]=temp;
  }
}

int main(){
  int n;
  cin>>n;
  int arr[n];

  for(int i=0;i<n;i++){
    cin>>arr[i];
  }

  selectionSort(arr, n);

  for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
  }

  return 0;
}

