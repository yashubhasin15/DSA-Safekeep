#include<iostream>
using namespace std;
#include<vector>

int main(){
  vector<int> v;
  v.push_back(1);
  v.push_back(2);
  v.push_back(3);

  cout<<v.at(0)<<endl;
  cout<<v[0]<<endl; 
  // both of the above will work but [] will also access that memory which is not ours whereas at will give error if we try to access that memmory
  //cout<<v[4]<<endl;//this will give garbage value
  //cout<<v.at(4)<<endl;//this will give error

  //we should use v[] only to access or modify previously added values but not to add new elements to the vector
  v[3]=4;
  v[4]=5;
  cout<<v.size()<<endl;//since we use [] to add elements and not push_back, the size would not have updated and we are changing memory which is not ours, we should not do this.
  v.pop_back();//this will pop 3, not 5 since the last index according to our vector is 2, this is updated in push_back function
  v.push_back(6);//this will add 6 at index 2 and update next index to 3, and also array size to double if required
  v.push_back(7);

  for(int i=0;i<v.size();i++){
    cout<<v[i]<<" ";
  }
  return 0;
}