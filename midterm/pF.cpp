#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<ll> e(n), a(n), b(n), sum(n, 0);
    vector<vector<ll>> k(n);
    for(auto &i: e) cin >> i;
      
    for(int i=1;i<n;i++){
        cin >> a[i] >> b[i];
    }
    for(int i=1;i<n;i++){
        k[i].push_back(0);
        for(int j=i;j<n-1;j+=i){
            k[i].push_back(j);
        }
        k[i].push_back(n-1);
    }
    for(int i=1;i<n;i++){
        int sz = k[i].size();
        for(int j=1;j<sz;j++){
            sum[i] += abs(e[k[i][j-1]]-e[k[i][j]]);
        }
    }
    vector<pair<ll, ll>> ans;
    for(int i=1;i<n;i++){
        ans.push_back({a[i]*((ll)k[i].size()-1)+b[i]*sum[i], i});
    }
    sort(ans.begin(), ans.end());
    cout << ans[0].second << " " << ans[0].first << endl;
    for(auto i: k[ans[0].second]){
        cout << i << " ";
    }
    cout << endl;
}