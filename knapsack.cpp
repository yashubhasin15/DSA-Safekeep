#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int knapsnackMemo(int n, int* weights, int* values, int w, vector<vector<int>> &dp){
    
    if(n==0 || w==0){
        return 0;
    }
    
    if(dp[n][w]!=-1){
        return dp[n][w];
    }
    
    int ans= knapsnackMemo(n-1,weights+1,values+1, w, dp);;
    if(weights[0]<=w){
        int x= values[0]+knapsnackMemo(n-1,weights+1,values+1, w-weights[0], dp);
        ans= max(ans, x); 
    }
    dp[n][w]=ans;
    return ans;
}

int knapsnackDP(int n, int* weights, int* values, int w){
    int dp[n+1][w+1];
    for(int i=0;i<=n;i++){
        dp[i][0]=0;
    }
    for(int j=0;j<=w;j++){
        dp[0][j]=0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=w;j++){
            dp[i][j]= dp[i-1][j];
            if(weights[i-1]<=j){
                dp[i][j]= max(dp[i][j],values[i-1]+dp[i-1][j-weights[i-1]]);
            }
        }
    }
    return dp[n][w];
}

int main(){
    // write your code here
    int n;
    cin>>n;
    int weights[n];
    int values[n];
    for(int i=0;i<n;i++){
        cin>>weights[i];
    }
    for(int i=0;i<n;i++){
        cin>>values[i];
    }
    int w;
    cin>>w;
    // vector<vector<int>> dp(n+1,vector<int>(w+1,-1));
    // cout<<knapsnackMemo(n,weights,values,w,dp)<<endl;
    cout<<knapsnackDP(n,weights,values,w);
    return 0;
}

// 6
// 10 5 8 1 10 7 
// 8 4 8 6 5 1 
// 13