#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int editDist(string s, string t){
    int n= s.size();
    int m= t.size();
    int dp[n+1][m+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i==0){
                dp[i][j]=j;
            }
            else if(j==0){
                dp[i][j]=i;
            }
            else{
                if(s[n-i]==t[m-j]){
                    dp[i][j]=dp[i-1][j-1];
                }
                else{
                    int x= dp[i-1][j-1];
                    int y= dp[i-1][j];
                    int z= dp[i][j-1];
					dp[i][j]=1+min(x,min(y,z));
                }
            }
            
        }
    }
    return dp[n][m];
}

int main(){
    string s,t;
    cin>>s>>t;
    cout<<editDist(s,t)<<endl;
    return 0;
}