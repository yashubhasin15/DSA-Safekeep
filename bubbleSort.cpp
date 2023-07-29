#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n) 
{ 
    int i, j; 
    for (i = 0; i < n-1; i++){
        for (j = 0; j < n-i-1; j++){
            if (arr[j] > arr[j+1]){
                int temp = arr[j]; 
                arr[j] = arr[j+1]; 
                arr[j+1] = temp;
            }
        }
    }
} 
  
int main() 
{ 
    int n;
    cin>>n;
    int arr[n];

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    bubbleSort(arr, n);
    cout<<"Sorted array: \n"; 
    for (int i = 0; i < n; i++) 
        cout << arr[i] << " "; 
    cout << endl; 
    return 0; 
} 