#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

int main(){
    int t;
    cin >> t;
    while (t--){
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges(n + 1);
        for (int i = 0; i < m; i++){
            int x, y;
            cin >> x >> y;
            edges[x].push_back(y);
        }
        int a, b, k;
        cin >> a >> b >> k;

        queue<int> q;
        for (auto &x : edges[a]){
            q.push(x);
            x = 0;
        }
        string ans;
        while (!q.empty()){
            int n = q.size();
            if (n < k) break;
            while (n--){
                auto top = q.front();
                q.pop();

                if (top == b){
                    k--;
                    continue;
                }
                for (auto &x : edges[top]){
                    if (x){
                        q.push(x);
                        x = 0;
                    }
                }
            }
        }
        if (k <= 0) ans = "YES";
        else ans = "NO";
        cout << ans << endl;
    }
    return 0;
}