#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int lcs(string str1, string str2){
    int n=str1.size();
    int m=str2.size();
    int dp[n+1][m+1];
    
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i==0 || j==0){
                dp[i][j]=0;
                continue;
            }
            if(str1[n-i]==str2[m-j]){
                dp[i][j]=1+dp[i-1][j-1];
            }
            else{
                dp[i][j]= max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    
    return dp[n][m]; 
}

int main(){
    string str1, str2;
    cin >> str1 >> str2;
    cout << lcs(str1, str2)<<endl;
    return 0;
}