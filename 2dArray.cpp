#include<iostream>
#include<string>
using namespace std;

int main(){
  int bruhh[5][3];
  int temp;
  for(int i=0;i<5;i++){
    for(int j=0;j<3;j++){
      cin>>temp;
      bruhh[i][j]=temp;
    }
  }
  for(int i=0;i<5;i++){
    for(int j=0;j<3;j++){
      cout<<bruhh[i][j]<<" ";
    }
  }
  return 0;
}