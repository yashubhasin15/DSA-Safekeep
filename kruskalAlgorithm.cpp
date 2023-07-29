#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Edge{
    public:
    int source;
    int destination;
    int weight;

    Edge(){}

    Edge(int a,int b, int c){
        source= a;
        destination= b;
        weight= c;
    }
};

bool comparator(Edge a, Edge b){
    return a.weight < b.weight;
}

void MST(vector<Edge> &input, vector<Edge> &output, int v, int e, int* parent){
    int count=0;
    for(int i=0;i<e && count<v;i++){
        int a1= input[i].source;
        int a2= input[i].destination;
        int p1= parent[a1];
        int p2= parent[a2];

        while(parent[p1]!=p1){
            p1=parent[p1];
        }
        while(parent[p2]!=p2){
            p2=parent[p2];
        }
        if(p1!=p2){
            output[count]= input[i];
            count++;
            parent[p1]=p2;
        }
    }
}

int main(){
    int v,e;
    cin>>v>>e;
    vector<Edge> input(e);
    vector<Edge> output(v-1);

    for(int i=0;i<e;i++){
        int s,d,w;
        cin>>s>>d>>w;
        input[i].source=s;
        input[i].destination=d;
        input[i].weight=w;
    }

    sort(input.begin(),input.end(),comparator);

    int* parent= new int[v];
    for(int i=0;i<v;i++){
        parent[i]=i;
    }

    MST(input,output,v,e,parent);

    cout<<endl;
    int mstWeight=0;
    for(int i=0;i<v-1;i++){
        mstWeight+=output[i].weight;
        if(output[i].source<output[i].destination){
            cout<<output[i].source<<" "<<output[i].destination<<" "<<output[i].weight<<endl;
        }
        else{
            cout<<output[i].destination<<" "<<output[i].source<<" "<<output[i].weight<<endl;
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