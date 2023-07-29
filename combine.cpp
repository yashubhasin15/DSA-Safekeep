#include<iostream>
#include<string>
#include<vector>
#include<unordered_set>
using namespace std;


void combine(string s , string answer, vector<int> &arr, int len)
{
    if(len == 0)
    {
        arr.push_back(stoi(answer));
        return;
    }
    for(int i=0 ; i<s.length() ; i++)
    {
        char ch = s[i];
        string rest = s.substr(i+1);
        combine(rest , answer+ch,arr,len-1);
    }
  
}

//if input contains a 2 digit number, then we cannot use the above string method. We need to use arrays to store numbers
void combine(int arr[], vector<int> temp, vector<vector<int>> &comb, int len, int size){
    if(len == 0)
    {
        comb.push_back(temp);
        return;
    }
    for(int i=0 ; i<size ; i++)
    {
        int a = arr[i];
        temp.push_back(a);
        combine(arr+1+i,temp,comb,len-1,size-1-i);
        temp.pop_back();
    }

}

int main(){
  string input= "12345";
  int len=3;
  string temp;
  vector<int> arr;
  combine(input,temp,arr,len);
  for(auto x:arr){
    cout<<x<<" ";
  }
  cout<<endl;

  // for combination of elements in an array
  int input1[]={12,95,9,354,7};
  vector<vector<int>> comb;
  vector<int> temp1;
  combine(input1,temp1,comb,len,5);
  for(auto x:comb){
    for(auto y:x){
      cout<<y<<" ";
    }
    cout<<endl;
  }
  return 0;
}