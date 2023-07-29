#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void dfs(vector<vector<int>> &edges,vector<bool> &visited,int sv, vector<int> &component){
    visited[sv]=true;
    component.push_back(sv);
    for(auto v: edges[sv]){ //this is faster method as we dont need to traverse each and every element in 2d vector and dont need to check the edges[sv][i]==1 condition everytime
        if(!visited[v]){
            dfs(edges,visited,v,component);
        }
    }
}

void connectedComponents(vector<vector<int>> &edges, vector<bool> &visited, int v){

    for(int i=0;i<v;i++){
        if(!visited[i]){
            vector<int> components;
            dfs(edges,visited,i,components);
            sort(components.begin(),components.end());
            for(int i=0;i<components.size();i++){
                cout<<components[i]<<" ";
            }
            cout<<endl;
            
        }
    }
}

int main(){
    int v,e;
    cin>>v>>e;
    vector<vector<int>> edges(v);
    for(int i=0;i<e;i++){
        int f,s;
        cin>>f>>s;
        edges[f].push_back(s); //this is faster method 
        edges[s].push_back(f);
    }
    vector<bool>visited(v,false);
    
    connectedComponents(edges,visited,v);
    return 0;
}

// 6 3
// 0 1
// 1 2
// 3 4