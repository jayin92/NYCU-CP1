#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll power(ll x, ll y, ll p){
    ll res = 1;
    x = x % p;
    while(y > 0){
        if(y & 1){
            res = (res * x) % p;
        }

        y = y >> 1;
        x = (x * x) % p;
    }

    return res;
}

void solve(){
    ll a, p;
    cin >> a >> p;
    ll ans = power(a, p-2, p);
    cout << ans << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}