#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;

int main(){
  unordered_map<string,int> mp;
  mp["abc"]=1;
  mp["abc1"]=2;
  mp["abc2"]=3;
  mp["abc3"]=4;
  mp["abc4"]=5;
  mp["abc5"]=6;

  unordered_map<string,int>::iterator it;//it is a pointer to a pair inside the unordered map
  for(it=mp.begin();it!=mp.end();it++){
    cout<<"Key: "<<it->first<<" Value: "<<it->second<<endl;
  }//since we are using unordered map, pairs will be printed in random order

  //find
  unordered_map<string,int>::iterator it1=mp.find("abc4");
  cout<<endl<<"Key: "<<it1->first<<" Value: "<<it1->second<<endl<<endl;

  //erase
  // mp.erase(it1); //so instead of keys, we can also pass itertor pointing to the pair we want to delete
  it1++;
  mp.erase(it1,mp.end());//we can delete a range of pairs, not including the second arguement
  for(it=mp.begin();it!=mp.end();it++){
    cout<<"Key: "<<it->first<<" Value: "<<it->second<<endl;
  }

  return 0;
}