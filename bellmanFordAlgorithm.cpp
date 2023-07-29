#include<iostream>
#include<vector>
#include<climits>
using namespace std;

typedef pair<int,int> ipair;

void bellman(vector<vector<ipair>> &edges,vector<int> &dist,int v,int e){
    for(int n=0;n<v-1;n++){
        for(int i=0;i<v;i++){
            if(dist[i]==INT_MAX){//because if a vertex is infinity, then it will never be able to relax its adjacent vertices. Also if we add anything to INT_MAX, it will wrap around and cause problems in line 18.
                continue;
            }
            for(auto u:edges[i]){
                int j= u.first;
                int weight= u.second;
                
                if(dist[j]>dist[i]+weight){
                    dist[j]=dist[i]+weight;
                }
            }
        }
    }
}

int main(){
    // write your code here
    int t;
    cin>>t;
    while(t--){
        int v,e,src,des;
        cin>>v>>e>>src>>des;
        vector<vector<ipair>> edges(v);
        for(int i=0;i<e;i++){
            int f,s,w;
            cin>>f>>s>>w;
            edges[f].push_back(make_pair(s,w));            
        }
        vector<int> dist(v,INT_MAX);
        dist[src]=0;
        bellman(edges,dist,v,e);
        
        cout<<dist[des]<<endl;
    }
    return 0;
}