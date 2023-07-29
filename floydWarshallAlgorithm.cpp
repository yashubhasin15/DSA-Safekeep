#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

void floyd(vector<vector<int>> &edges, int v,int e){
    for(int k=0;k<v;k++){
        for(int i=0;i<v;i++){
            for(int j=0;j<v;j++){
                if(edges[i][k]!=INT_MAX && edges[k][j]!=INT_MAX ){
                    edges[i][j]=min(edges[i][j],edges[i][k]+edges[k][j]);
                }
            }
        }
    }
}

int main(){
    
    // write your code here
    int v,e;
    cin>>v>>e;
    vector<vector<int>> edges(v,vector<int>(v,INT_MAX));//we are using edges matrix like distance in this question, edges[i][j] is the distance between ith and jth vertex,thats why we initialised with infinity
    for(int i=0;i<v;i++){//since the dist between ith and ith vertex is 0
        edges[i][i]=0;
    }
    for(int i=0;i<e;i++){
        int f,s,w;
        cin>>f>>s>>w;
        edges[f][s]=min(w,edges[f][s]); //just incase someone inputs same edge twice with different weights
        edges[s][f]=edges[f][s];
    }
    
    floyd(edges,v,e);

    int q; //no of queries
    cin>>q;
    while(q--){
        int a,b;//vertices between which distance is to be found
        cin>>a>>b;
        cout<<edges[a][b]<<endl;
    }
    return 0;
}

// 3 6
// 2 0 4
// 0 2 17
// 1 2 2
// 0 2 7
// 2 1 11
// 1 2 15
// 3
// 2 2 
// 0 1 
// 1 2