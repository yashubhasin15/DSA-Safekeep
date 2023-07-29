#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int minWeightIndex(vector<bool> &visited, vector<int> &weight,int v){
    int minIndex=-1;
    for(int i=0;i<v;i++){
        if(!visited[i] && (minIndex==-1 || weight[i]<weight[minIndex])){
            minIndex=i;
        }
    }
    return minIndex;
}

void prims(vector<vector<int>> &edges,int v,int e, vector<bool> &visited, vector<int> &weight, vector<int> &parent){
    for(int i=0;i<v-1;i++){
        int minIndex= minWeightIndex(visited,weight,v);
        visited[minIndex]=true;

        for(int j=0;j<v;j++){
            if(edges[minIndex][j]!=0 && !visited[j]){
                if(weight[j]>edges[minIndex][j]){
                    weight[j]=edges[minIndex][j];
                    parent[j]=minIndex;
                }
            }
        }
    }
}

int main(){
    int v,e;
    cin>>v>>e;
    vector<vector<int>> edges(v,vector<int>(v,0));
    for(int i=0;i<e;i++){
        int f,s,w;
        cin>>f>>s>>w;
        edges[f][s]=w;
        edges[s][f]=w;
    }
    vector<bool> visited(v,false);
    vector<int> weight(v,INT_MAX);
    weight[0]=0;
    vector<int> parent(v);
    parent[0]=-1;

    prims(edges,v,e,visited,weight,parent);
    
    cout<<endl;
    int mstWeight=0;
    for(int i=1;i<v;i++){
        mstWeight+=weight[i];
        if(parent[i]<i){
            cout<<parent[i]<<" "<<i<<" "<<weight[i]<<endl;
        }
        else{
            cout<<i<<" "<<parent[i]<<" "<<weight[i]<<endl;
        }
    }
    cout<<"mst weight: "<<mstWeight;

    return 0;
}

// 6 8
// 3 5 13
// 3 0 5
// 0 2 10
// 1 3 12
// 4 3 8
// 2 3 6
// 0 4 10
// 4 1 8