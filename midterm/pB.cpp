#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<set<ll>> row(5e5+5);
vector<set<ll>> col(5e5+5);

void dis(ll x, ll y){
    auto it1 = row[x].lower_bound(y);
    auto it3 = col[y].lower_bound(x);
    vector<pair<ll, pair<ll, ll>>> a;
    if(it1 != row[x].end()){
        a.push_back({abs(y - *it1), {x, *it1}});
    }
    if((ll)row[x].size() != 0 && it1 != row[x].begin()){
        it1 --;
        a.push_back({abs(y - *it1), {x, *it1}});
    }
    if(it3 != col[y].end()){
        a.push_back({abs(x - *it3), {*it3, y}});
    }
    if((ll)col[y].size() != 0 and it3 != col[y].begin()){
        it3 --;
        a.push_back({abs(x - *it3), {*it3, y}});
    }
    
    ll sz = a.size();
    if(sz == 0){
        cout << -1 << endl;
        return;
    }
    sort(a.begin(), a.end());
    cout << a[0].first << endl;
    for(ll i=0;i<sz;i++){
        ll c = a[i].second.first;
        ll d = a[i].second.second;
        // cerr << a[i].first << " " << c <<  " " << d << endl;
        if(a[i].first == a[0].first){
            row[c].erase(d);
            col[d].erase(c);
        }
    }
}

int main(){
    ll n, m, w, q;
    cin >> n >> m >> w >> q;

    ll x, y;
    for(ll i=0;i<w;i++){
        cin >> x >> y;
        row[x].insert(y);
        col[y].insert(x);
    }
    ll r, s, c, d;
    for(ll i=0;i<q;i++){
        // for(ll ii=0;ii<n;ii++){
        //     for(ll j=0;j<m;j++){
        //         if(row[ii].find(j) != row[ii].end()){
        //             cout << "X";
        //         } else {
        //             cout << ".";
        //         }
        //     }
        //     cout << endl;
        // }
        cin >> r >> c >> s >> d;
        dis(r, c);
        row[s].insert(d);
        col[d].insert(s);
    }
    return 0;
}