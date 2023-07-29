#include<iostream>
#include<string>
#include<vector>
#include<unordered_set>
using namespace std;

void permute(string s , string answer, unordered_set<int> &arr)
{
    if(s.length() == 0)
    {
      arr.insert(stoi(answer));
      return;
    }
    for(int i=0 ; i<s.length() ; i++)
    {
        char ch = s[i];
        string left_substr = s.substr(0,i);
        string right_substr = s.substr(i+1);
        string rest = left_substr + right_substr;
        permute(rest , answer+ch,arr);
    }
  
}

int main(){
  string input;
  cin>>input;
  string ans;
  unordered_set<int> arr;
  permute(input,ans,arr);
  for(auto x:arr){
    cout<<x<<" ";
  }
  return 0;
}