#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
using namespace std;

//Question 1
int longestConsecutiveSequence(int* arr,int n){
  unordered_set<int> S;
  int ans = 0;

  for (int i = 0; i < n; i++){
    S.insert(arr[i]);
  }

  for (int i = 0; i < n; i++){
    if (S.find(arr[i] - 1) == S.end()){
      int j = arr[i];
      while (S.find(j) != S.end()){
        j++;
      }

      ans = max(ans, j - arr[i]);
    }
  }
  return ans;
}

// int longestConsecutiveSequence2(int arr[],int n){
//   unordered_map<int,bool> mp;
//   for(int i=0;i<n;i++){
//     mp[arr[i]]=true;
//   }

//   int ans=0;
//   int count=0;

//   for(int i=0;i<n;i++){
//     if(mp[arr[i]]==true){
//       mp[arr[i]]=false;
//       count=1;
//       int smaller= arr[i]-1;
//       int bigger= arr[i]+1;

//       while(mp.find(smaller)!=mp.end()){
//         mp[smaller]=false;
//         count++;
//         smaller--;
//       }
//       while(mp.find(bigger)!=mp.end()){
//         mp[bigger]=false;
//         count++;
//         bigger++;
//       }
//       ans=max(ans,count);
//     }
//   }
//   return ans;
// }


//Question 2
int pairsWithDifferenceK(int *arr, int n, int k) {
  unordered_map<int,int> mp;
  int count=0;
  for(int i=0;i<n;i++){
    mp[arr[i]]++;
  }
  unordered_map<int,int>::iterator it,it1,it2;
  for(it=mp.begin();it!=mp.end();){
    if(k==0){
      for(int i=1;i<it->second;i++){
        count+= i;
      }
    }
    else{
      it1= mp.find(it->first+k);
      it2= mp.find(it->first-k);
      if(it1!=mp.end()){
        count+= it->second*it1->second;
      }
      if(it2!=mp.end()){
        count+= it->second*it2->second;
      }
    }
    
    it=mp.erase(it);
  }
  return count;
}

// int pairsWithDifferenceK2(int* arr,int n,int k){
//   int count=0;
//   unordered_map<int,int> mp;
//   for(int i=0;i<n;i++){
//     count+= mp[arr[i]+k];
//     if(k!=0){
//     	count+= mp[arr[i]-k];
//     }
//     mp[arr[i]]++;
//   }
//   return count;
// }


//Question 3
int longestConsecutiveZeroSum(int* arr, int n){
  int sum=0;
  int len=0;
  unordered_map<int,int> mp;
  mp[0]=-1;//so that if the sequence starting from 0th index sums up to 0, we do len=i-mp[sum]=i-mp[0]=i-(-1)=i+1

  for(int i=0;i<n;i++){
    sum+= arr[i];
    if(mp.find(sum)!=mp.end()){
      len=max(len,i-mp[sum]);
    }
    else{
      mp[sum]=i;
    }
  }
  return len;
}

int main(){
  //Question 1
  int n;
  cin>>n;
  int* arr=new int[n];
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  cout<<"length of longest consecutive sequence is "<<longestConsecutiveSequence(arr,n)<<endl;

  // 7 9 1 3 10 4 20 2

  //Question 2
  int n1,k;
  cin>>n1>>k;
  int* arr1=new int[n1];
  for(int i=0;i<n1;i++){
    cin>>arr1[i];
  }
  cout<<"Number of pairs with difference "<<k<<" are "<<pairsWithDifferenceK(arr1,n1,k)<<endl;

  // 9 3 2 -1 3 5 6 0 -1 2 6

  //Question 3
  int n2;
  cin>>n2;
  int* arr2=new int[n2];
  for(int i=0;i<n2;i++){
    cin>>arr2[i];
  }
  cout<<"length of longest consecutive zero sum subset is "<<longestConsecutiveZeroSum(arr2,n2)<<endl;

  // 8 15 -2 2 -8 1 7 10 23 

  return 0;
}

