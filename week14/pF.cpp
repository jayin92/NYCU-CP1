// :80 <enter>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<int, ll> pil;
typedef pair<ll, int> pli;
typedef pair<double,double> pdd;
#define SQ(i) ((i)*(i))
#define MEM(a, b) memset(a, (b), sizeof(a))
#define SZ(i) int(i.size())
#define FOR(i, j, k, in) for (int i=j ; i<(k) ; i+=in)
#define RFOR(i, j, k, in) for (int i=j ; i>=(k) ; i-=in)
#define REP(i, j) FOR(i, 0, j, 1)
#define REP1(i,j) FOR(i, 1, j+1, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)
#define ALL(_a) _a.begin(),_a.end()
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define X first
#define Y second
#ifdef jayinnn
#define TIME(i) Timer i(#i)
#define debug(...) do{\
    fprintf(stderr,"%s - %d (%s) = ",__PRETTY_FUNCTION__,__LINE__,#__VA_ARGS__);\
    _do(__VA_ARGS__);\
}while(0)
template<typename T>void _do(T &&_x){cerr<<_x<<endl;}
template<typename T,typename ...S> void _do(T &&_x,S &&..._t){cerr<<_x<<", ";_do(_t...);}
template<typename _a,typename _b> ostream& operator << (ostream &_s,const pair<_a,_b> &_p){return _s<<"("<<_p.X<<","<<_p.Y<<")";}
template<typename It> ostream& _OUTC(ostream &_s,It _ita,It _itb)
{
    _s<<"{";
    for(It _it=_ita;_it!=_itb;_it++)
    {
        _s<<(_it==_ita?"":",")<<*_it;
    }
    _s<<"}";
    return _s;
}
template<typename _a> ostream &operator << (ostream &_s,vector<_a> &_c){return _OUTC(_s,ALL(_c));}
template<typename _a> ostream &operator << (ostream &_s,set<_a> &_c){return _OUTC(_s,ALL(_c));}
template<typename _a> ostream &operator << (ostream &_s,deque<_a> &_c){return _OUTC(_s,ALL(_c));}
template<typename _a,typename _b> ostream &operator << (ostream &_s,map<_a,_b> &_c){return _OUTC(_s,ALL(_c));}
template<typename _t> void pary(_t _a,_t _b){_OUTC(cerr,_a,_b);cerr<<endl;}
#define IOS()
class Timer {
private:
    string scope_name;
    chrono::high_resolution_clock::time_point start_time;
public:
    Timer (string name) : scope_name(name) {
        start_time = chrono::high_resolution_clock::now();
    }
    ~Timer () {
        auto stop_time = chrono::high_resolution_clock::now();
        auto length = chrono::duration_cast<chrono::microseconds>(stop_time - start_time).count();
        double mlength = double(length) * 0.001;
        debug(scope_name, mlength);
    }
};
#else
#define TIME(i)
#define debug(...)
#define pary(...)
#define endl '\n'
#define IOS() ios_base::sync_with_stdio(0);cin.tie(0)
#endif

const ll MOD = 1000000007;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int iNF = 0x3f3f3f3f;
const ll MAXN = 100005;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

vector<vector<int>> adj;
vector<vector<int>> p;
vector<int> d;
vector<int> sz;


int dfs(int cur, int par, int dep){
    debug(cur, par, dep);
    d[cur] = dep;
    p[cur][0] = par;
    int res = 1;
    for(auto i: adj[cur]){
        if(i != par){
            res += dfs(i, cur, dep+1);
        }
    }
    return sz[cur] = res;
}

int lca(int x, int y){
    if(d[x] > d[y]) swap(x, y);
    if(d[x] != d[y]){
        int diff = d[y] - d[x];
        for(int i=0;i<20;i++){
            if(diff & 1) y = p[y][i];
            diff >>= 1;
        }
    }
    if(x == y) return x;
    for(int i=19;i>=0;i--){
        if(p[x][i] != p[y][i]){
            x = p[x][i];
            y = p[y][i];
        }
    }

    return p[x][0];
}

void solve(){
    int n;
    cin >> n;
    adj.resize(n+1);
    p.resize(n+1, vector<int>(20, 0));
    d.resize(n+1);
    sz.resize(n+1, 0);
    vector<int> root;
    for(int i=1, j;i<=n;i++){
        cin >> j;
        if(j == 0){
            root.push_back(i);
        } else {
            adj[i].push_back(j);
            adj[j].push_back(i);
        }
    }
    for(auto i: root){
        dfs(i, 0, 1);
    }
    for(int i=1;i<20;i++){
        for(int j=1;j<=n;j++){
            p[j][i] = p[p[j][i-1]][i-1];
        }
    }
    int q, m, tmp;
    cin >> q;
    while(q--){
        cin >> m;
        list<int> a;
        for(int i=0;i<m;i++){
            cin >> tmp;
            a.push_back(tmp);
        }
        while(true){
            bool flag = true;
            for(auto i=a.begin();i!=a.end();i++){
                for(auto j=next(i);j!=a.end();j++){
                    int lc = lca(*i, *j);
                    if(lc == *i || lc == *j){
                        if(lc == *i){
                            a.erase(j);
                        } else {
                            a.erase(i);
                        }
                        flag = false;
                        break;
                    }
                }
                if(!flag) break;
            }
            if(flag) break;
        }
        ll ans = 0;
        for(auto i: a){
            ans += sz[i];
        }
        cout << ans << endl;
    }

}

/********** Good Luck :) **********/
int main () {
    TIME(main);
    IOS();
    int t = 1;
    while(t--){
        solve();
    }

    return 0;
}
