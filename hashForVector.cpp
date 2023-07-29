#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

struct hashFunction {
    size_t operator()(const vector<int> 
                    &myVector) const 
    {
    std::hash<int> hasher;
    size_t answer = 0;

    for (int i : myVector) 
    {
        answer ^= hasher(i) + 0x9e3779b9 + 
                (answer << 6) + (answer >> 2);
    }
    return answer;
    }
};

int main(){
    unordered_set<vector<int>,hashFunction> us;
    us.insert({1,2,3});
    us.insert({1,2,3});
    us.insert({3,2,3});
    us.insert({1,3,2});
    us.insert({1,3,2});
    for(auto x:us){
        for(auto y:x){
            cout<<y<<" ";
        }
        cout<<endl;
    }

    return 0;
}