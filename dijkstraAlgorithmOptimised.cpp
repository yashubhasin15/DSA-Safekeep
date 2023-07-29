#include<iostream>
#include<utility>
#include<vector>
#include<climits>
#include<queue>
using namespace std;

typedef pair<int,int> iPair;

void dijkstra(vector<vector<iPair>> &edges,vector<int> &distance, int v, int e){
    priority_queue<iPair,vector<iPair>,greater<iPair>> pq;
    //since we want to sort on the basis of distance, and priority queues of pair type use first value of pair to sort, we will put distance as first and vertex as second value in pair
    pq.push(make_pair(0,0));

    while(!pq.empty()){
        int i= pq.top().second; //this will give min distance edge
        pq.pop(); //this will work like visited, as this edge with min distance is popped and we wont visit it again

        for(auto x:edges[i]){
            int weight= x.second;
            int j= x.first;

            if(distance[j] > distance[i]+weight){
                distance[j]= distance[i]+weight;
                pq.push(make_pair(distance[j],j));
            }
        }
    }
}

int main(){
    int v,e;
    cin>>v>>e;
    vector<vector<iPair>> edges(v);//we are using adjacency list instead of matrix so that we iterate only over those vertices which have an edge with our vertex
    for(int i=0;i<e;i++){
        int f,s,w;
        cin>>f>>s>>w;
        edges[f].push_back(make_pair(s,w));
        edges[s].push_back(make_pair(f,w));
    }

    vector<int> distance(v,INT_MAX);
    distance[0]=0;
    dijkstra(edges,distance,v,e);

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