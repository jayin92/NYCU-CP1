#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
typedef long long ll;

vector<ll> pre(1e6+5, 0);

ll sum(int l, int r){
    if(l > r) return 0;
    else return pre[r] - pre[l-1];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<ll> h(n+1);
    stack<pair<ll, ll>> s;
    for(int i=1;i<=n;i++){
        cin >> h[i];
    }
    for(int i=1;i<=n;i++){
        cin >> pre[i];
        pre[i] += pre[i-1];
    }
    
    ll ans = 0;
    for(int i=1;i<=n;i++){
        while(!s.empty() && s.top().first > h[i]){
            ll x = s.top().first;
            s.pop();
            ll idx;
            if(s.empty()){
                idx = 0;
            } else {
                idx = s.top().second;
            }
            ans = max(ans, x*2LL/3LL*(sum(idx+1LL, i-1)));
        }
        s.push({h[i], i});
    }
    while(!s.empty()){
        ll x = s.top().first;
        s.pop();
        ll idx;
        if(s.empty()){
            idx = 0;
        } else {
            idx = s.top().second;
        }
        ans = max(ans, x*2LL/3LL*(sum(idx+1LL, n)));
    }
    cout << ans << endl;
}