#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int minPath(vector<bool> &visited, vector<int> &distance, int v){
    int minDistPath=-1;
    for(int i=0;i<v;i++){
        if(!visited[i] && (minDistPath==-1 || distance[i]< distance[minDistPath])){
            minDistPath=i;
        }
    }
    return minDistPath;
}

void dijkstra(vector<vector<int>> edges,int v,int e,vector<int> &distance, vector<bool> &visited){
    for(int i=0;i<v-1;i++){
        int minDistPath= minPath(visited,distance,v);
        visited[minDistPath]=true;
        for(int j=0;j<v;j++){
            if(edges[j][minDistPath]!=0 && !visited[j]){
                int tempDist= distance[minDistPath] + edges[j][minDistPath];
                if(tempDist<distance[j]){
                    distance[j]=tempDist;
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

    vector<int>distance(v,INT_MAX);
    distance[0]=0;
    vector<bool>visited(v,false);
    dijkstra(edges,v,e,distance,visited);
    
    cout<<endl;
    for(int i=0;i<v;i++){
        cout<<i<<" "<<distance[i]<<endl;
    }
    return 0;
}

// 4 4
// 0 1 3
// 0 3 5
// 1 2 1
// 2 3 8