#include<iostream>
#include<vector>
#include <cstring>
using namespace std;

class Sieve{
  public:
  bool primes[1000001];

  Sieve(){
    memset(primes, true, sizeof(primes));
    primes[0]=primes[1]=0;
    for(int i=2;i*i<1000001;i++){
      if(primes[i]){
        for(int j=i*i;j<1000001;j+=i){
          primes[j]=0;
        }
      }
	}
  }
	
};

int main(){
  int q;
	cin>>q;
	vector<vector<int>> arr(q,vector<int>(3,0));
	for(int i=0;i<q;i++){
		cin>>arr[i][0]>>arr[i][1]>>arr[i][2];
	}
	
	Sieve s;
	
	for(int i=0;i<arr.size();i++){
		int a=arr[i][0];
		int b=arr[i][1];
		int k=arr[i][2];
		int count=0;
		for(int j=a;j<=b;j++){
			if(s.primes[j]){
				count++;
				if(count==k){
					cout<<j<<endl;
					break;
				}
			}
		}
    if(count!=k){
			cout<<-1<<endl;
		}
	}
	
  return 0;
}