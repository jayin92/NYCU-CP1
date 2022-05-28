#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

typedef unsigned long long ll;
vector<ll> pre(1e6+5, 0);

ll get(ll l, ll r){
    if(r < l) return 0;
    return (pre[r] - pre[l-1]) * (r - l + 1LL); 
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n, q;
    cin >> n >> q;
    multiset<ll> mxVal;
    set<ll> idxL;
    set<ll> idxR;
    
    for(ll i=1;i<=n;i++){
        cin >> pre[i];
        pre[i] += pre[i-1];
    }
    idxL.insert(1);
    idxR.insert(n+1);
    ll total = pre[n] * n;
    mxVal.insert(total);
    while(q--){
        string op;
        cin >> op;
        if(op == "D"){
            ll x;
            cin >> x;
            x++;
            auto l = prev(idxL.upper_bound(x));
            auto r = idxR.upper_bound(x);
            ll l_idx = *l;
            ll r_idx = *r;
            idxL.erase(l_idx);
            idxR.erase(r_idx);
            if(l_idx < x){
                idxL.insert(l_idx);
                idxR.insert(x);
            }
            if(x+1 < r_idx){
                idxL.insert(x+1);
                idxR.insert(r_idx);
            }
            ll val = get(l_idx, r_idx-1);
            ll lsum = get(l_idx, x-1);
            ll rsum = get(x+1, r_idx-1);
            total = total - val + lsum + rsum;
            auto it = mxVal.find(val);
            if(it != mxVal.end()) mxVal.erase(it);
            if(lsum != 0) mxVal.insert(lsum);
            if(rsum != 0) mxVal.insert(rsum);
        } else if(op == "QS"){
            cout << total << endl;
        } else if(op == "QM"){
            cout << *(mxVal.rbegin()) << endl;
        }
    }
}