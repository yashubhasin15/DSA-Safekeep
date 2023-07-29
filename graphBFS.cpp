#include<iostream>
#include<queue>
#include<vector>
#include<unordered_map>
using namespace std;

void printBFS(int** edges, int n, int sv, bool* visited){
    queue<int> q;
    q.push(sv);
    visited[sv]=true;    

    while(!q.empty()){
        int top= q.front();
        q.pop();
        cout<<top<<endl;

        for(int i=0;i<n;i++){
            if(edges[top][i]==1 && !visited[i]){
                q.push(i);
                visited[i]=true;
            }
        }
    }
}

void BFS(int** edges, int n){
    bool* visited= new bool[n];
    for(int i=0;i<n;i++){
        visited[i]=false; //initialising bool array with false
    }

    for(int i=0;i<n;i++){
        if(!visited[i]){
            printBFS(edges,n,i,visited);
        }
    }
    delete [] visited;
}

bool hasPath(int** edges, int n, int v1, int v2, vector<bool> &visited, vector<int> &path){

    queue<int> pendingVertices;
    pendingVertices.push(v1);
    visited[v1]=true;
    unordered_map<int,int> mp;

    while(!pendingVertices.empty()){
        int top= pendingVertices.front();
        pendingVertices.pop();
        if(edges[top][v2]==1){
            path.push_back(v2);
            while(top!=v1){
                path.push_back(top);
                top= mp[top];
            }
            path.push_back(v1);
            return true;
        }

        for(int i=0;i<n;i++){
            if(edges[top][i]==1 && !visited[i]){
                mp[i]=top;
                pendingVertices.push(i);
                visited[i]=true;
            }
        }
    }

    return false;    
}

int main(){
    int n,e; //n is number of vertices and e is number of edges
    cin>>n>>e;
    int**edges= new int*[n];
    for(int i=0;i<n;i++){
        edges[i]= new int[n];
        for(int j=0;j<n;j++){
            edges[i][j]=0;
        }
    }

    for(int i=0;i<e;i++){
        int f,s;
        cin>>f>>s;
        edges[f][s]=1;
        edges[s][f]=1;
    }

    cout<<"Enter the two vertices to find path: "<<endl;
    int v1,v2;
    cin>>v1>>v2;

    vector<bool> visited(n,false);
    vector<int> path;

    if(hasPath(edges,n,v1,v2,visited,path)){
        cout<<"path exists"<<endl;
        for(int i=0;i<path.size();i++){
            cout<<path[i]<<" ";
        }
    }
    else{
        cout<<"no path exists"<<endl;
    }
    for(int i=0;i<n;i++){
        delete [] edges[i];
    }
    delete edges;


    return 0;
}

// 8 7
// 0 1
// 1 3
// 3 4
// 4 5
// 1 5
// 0 2
// 6 7
