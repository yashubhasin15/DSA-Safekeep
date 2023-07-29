#include<iostream>
using namespace std;
#include<vector>
#include<unordered_map>
#include<string>

vector<int> removeDuplicates(int* arr, int n){//if we do this by iterating over one array and checking in other array, it will take O(N2) complexity, but if we use map instead of second array, checking will take O(1) and problem will be done in O(N)
  vector<int> output;
  unordered_map<int,bool> seen;
  for(int i=0;i<n;i++){
    if(seen.count(arr[i])>0){
      continue;
    }
    seen[arr[i]]=true;// this will take O(1) time complexity. if we use normal map instead of unordered map, time comp. is O(N)
    output.push_back(arr[i]);
  }
  return output;
}

int main(){
  unordered_map<string,int> mp;

  //insert function accepts a pair as arguement
  pair<string,int> p("abc",1);
  mp.insert(p);
  //we can also insert like below
  mp["def"]=3;

  //access
  cout<<mp.at("def")<<endl; //this will check for def and return corresponding value. if def is not present, it will throw error
  cout<<mp["def"]<<endl; //this will check for def and return corresponding value. if def is not present, it will insert def with value 0 and return 0;

  cout<<"size: "<<mp.size()<<endl;

  cout<<mp["ghi"]<<endl;//this will create ghi with value 0 and return 0
  cout<<"size: "<<mp.size()<<endl;

  //since .at() method will give error and square bracket will add string, we cant check if a string is present or not using the above 2 methods
  if(mp.count("ghi")>0){ //this will return 1 if ghi already exits and 0 if it does not exist
    cout<<"ghi is present"<<endl;
  }

  //erase
  mp.erase("ghi");
  cout<<"size: "<<mp.size()<<endl;
  if(mp.count("ghi")>0){ //now this will not print as ghi is erased
    cout<<"ghi is present"<<endl;
  }

  //Question: remove duplicates elements from an array;
  int arr[]={1,2,2,3,4,4,5,6,7,8,9,9};
  vector<int> ans= removeDuplicates(arr,sizeof(arr)/sizeof(arr[0]));
  for(int i=0;i<ans.size();i++){
    cout<<ans[i]<<" ";
  }
  return 0;
}

