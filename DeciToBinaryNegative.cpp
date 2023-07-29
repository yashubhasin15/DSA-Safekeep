#include<iostream>
#include<string>
#include<cmath>
using namespace std;
int main(){
  int n;
  cin>>n;
  string ans;
  int i=0;
  if(n<0){
    //find compliment
    n= ~(abs(n));
    // do binary addition with 1
    int carry= 1;
    int j=0;
    while(carry){
      carry= n&(1<<j);
      n= n^(1<<j);
      j++;
    }
  }
  for(int i=31;i>=0;i--){
      if(n&(1<<i)){
        ans+= "1";
      }
      else{
        ans+= "0";
      }
  }
  cout<<ans;

}