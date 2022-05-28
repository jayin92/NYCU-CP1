#include <bits/stdc++.h>

using namespace std;

int main(){
    
    int n, q;
    cin >> n >> q;
    vector<priority_queue<pair<int, int>>> a(n+1);
    set<pair<int, int>> s;
    int p;
    while(q--){
        cin >> p;
        if(p == 1){
            int u, v, d;
            cin >> u >> v >> d;
            if(d > 0){
                a[v].push({d, u});
            } else if(d == 0){
                continue;
            } else {
                a[u].push({d, v});
            }
        } else {
            int v;
            cin >> v;
            if(a[v].empty()){
                cout << "nothing" << endl;
            } else {
                cout << a[v].top().second << endl;
            }
        }
    }   
}