#include<iostream>
#include<vector>

using namespace std;

int dfs(vector<vector<int>> &adj,int a,int b,vector<bool>& v){
    if(a==b) return 1;
    
    v[a]= true;
    int p=0;
    for(int i:adj[a]){
        if(v[i]) continue;
        p+= dfs(adj,i,b,v);
    }
    v[a]= false;
    return p;
}

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<vector<int>> adj(n+1,vector<int>());
        for(int i=0;i<m;i++){
            int a,b;
            cin>>a>>b;
            adj[a].push_back(b);
        }
        int a,b,k;
        cin>>a>>b>>k;
        vector<bool>v(n+1,false);
        int u=dfs(adj,a,b,v);
        cout<<u<<endl;
        if(u>=k)
        cout<<"y";
        else
        cout<<"no";
        cout<<endl;
    }

    return 0;
}