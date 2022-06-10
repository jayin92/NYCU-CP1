#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

typedef long long ll;

vector<int> par; // index
vector<ll> sz;
vector<ll> pre;

ll sum(int l, int r){
    if(l == 0) return pre[r];
    else return pre[r] - pre[l-1];
}

int find(int x){
    if(par[x] == x) return x;
    else return par[x] = find(par[x]);
}

void merge(int a, int b){
    int fa = find(a);
    int fb = find(b);
    if(fa == fb) return;
    if(sz[fa] < sz[fb]) swap(fa, fb);
    par[fb] = fa;
    sz[fa] += sz[fb];
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    vector<ll> ans;
    vector<ll> del_order;
    vector<int> query; // -1 for del, 0 for all, 1 for max
    vector<bool> run(n, true);
    string tmp;
    int x;
    
    par.resize(n);
    pre.resize(n);
    sz.resize(n, 1);
    par[0] = 0;
    cin >> pre[0];
    for(int i=1;i<n;i++){
        par[i] = i;
        cin >> pre[i];
        pre[i] += pre[i-1];
    }
    for(int i=0;i<q;i++){
        cin >> tmp;
        if(tmp == "D"){
            cin >> x;
            del_order.push_back(x);
            run[x] = false;
            query.push_back(-1);
        } else if(tmp == "QS"){
            query.push_back(0);
        } else {
            query.push_back(1);
        }
    }
    int l = 0;
    int r = 0;
    bool flag = run[0];
    ll cur_max = 0;
    ll total = 0;
    for(int i=1;i<n;i++){
        if(flag == false && run[i]){
            l = i;
            flag = true;
        } else if(run[i] && run[i-1]){
            merge(i, i-1);
            if(!flag){
                l = i;
                flag = true;
            }
        } else if(flag && run[i] == false){
            cur_max = max(cur_max, (i-1-l+1) * sum(l, i-1));
            total += (i-1-l+1) * sum(l, i-1);
            flag = false;
        }
    }
  
    if(flag){
        cur_max = max(cur_max, (ll)(n-1-l+1) * sum(l, n-1));
        total += (ll)(n-1-l+1) * sum(l, n-1);
    }
    // for(int i=0;i<n;i++){
    //     cout << i << " " << par[i] << endl;
    // }
    int idx = 0;
    reverse(query.begin(), query.end());
    reverse(del_order.begin(), del_order.end());
    for(int i=0;i<q;i++){
        if(query[i] == 0){
            ans.push_back(total);
        } else if(query[i] == 1){
            ans.push_back(cur_max);
        } else {
            x = del_order[idx++];
            run[x] = true;
            // cout << "x: " << x << endl;
            if(x == 0 || x == n-1){
                if(x == 0){
                    if(run[x+1]){
                        r = x + sz[find(x+1)];
                        total = total - (sz[find(x+1)] * sum(x+1, r)) + (ll)(1 + sz[find(x+1)]) * sum(x, r) ;
                        cur_max = max(cur_max, (ll)(1 + sz[find(x+1)]) * sum(x, r));
                        merge(x, x+1);
                    } else {
                        total += sum(x, x);
                        cur_max = max(cur_max, sum(x, x));
                    }
                } else {
                    if(run[x-1]){
                        l = x - sz[find(x-1)];
                        total = total - (sz[find(x-1)] * sum(l, x-1)) + (ll)(1 + sz[find(x-1)]) * sum(l, x);
                        cur_max = max(cur_max, (ll)(1 + sz[find(x-1)]) * sum(l, x));
                        merge(x-1, x);
                    } else {
                        total += sum(x, x);
                        cur_max = max(cur_max, sum(x, x));
                    }
                }
            } else {
                // merge w/ left and right
                // cur_max = (sz[x-1] + 1 + sz[x+1]) * sum(l, r);
                if(run[x-1] && run[x+1]){
                    l = x - sz[find(x-1)];
                    r = x + sz[find(x+1)];
                    total = total - (sz[find(x-1)] * sum(l, x-1)) - (sz[find(x+1)] * sum(x+1, r)) + (ll)(sz[find(x-1)] + 1 + sz[find(x+1)]) * sum(l, r);
                    cur_max = max(cur_max, (ll)(sz[find(x-1)] + 1 + sz[find(x+1)]) * sum(l, r));
                    merge(x-1, x);
                    merge(x, x+1);
                } else if(run[x-1]){
                    l = x - sz[find(x-1)];
                    total = total - (sz[find(x-1)] * sum(l, x-1)) + (ll)(1 + sz[find(x-1)]) * sum(l, x);
                    cur_max = max(cur_max, (ll)(1 + sz[find(x-1)]) * sum(l, x));
                    merge(x-1, x);
                } else if(run[x+1]){
                    r = x + sz[find(x+1)];
                    total = total - (sz[find(x+1)] * sum(x+1, r)) + (ll)(1 + sz[find(x+1)]) * sum(x, r);
                    cur_max = max(cur_max, (ll)(1 + sz[find(x+1)]) * sum(x, r));
                    merge(x, x+1);
                } else {
                    total += sum(x, x);
                    cur_max = max(cur_max, sum(x, x));
                }
            }
        }
    }
    reverse(ans.begin(), ans.end());
    for(auto i: ans){
        cout << i << endl;
    }
    
}