#include <iostream>
using namespace std;


int main(){
  int n,m;
  cin>>n>>m;
  //we cant just write new int[4][5] to make 2d array in the heap, so we have to make an array of pointers each pointing to a new array

  int** dp= new int*[n];//we created an array of pointers in the heap and made a double pointer in the stack pointing towards the array
  for(int i=0;i<n;i++){
    dp[i]= new int[m];//each pointer in the array will point towards a new array
    for(int j=0;j<m;j++){
      cin>>dp[i][j];
    }
  }

  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      cout<<dp[i][j]<<" ";
    }
    cout<<endl;
  }

  //now first we need to delete the sub arrays and then delete the main array of pointers
  for(int i=0;i<n;i++){
    delete [] dp[i];
  }
  delete [] dp;

  return 0;
}

