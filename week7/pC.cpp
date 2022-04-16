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

bool isVowel(char c){
    return c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
}

bool check(vector<bool> s){
    int n = s.size();
    for(int i=0;i<n-2;i++){
        if((s[i] == s[i+1]) and (s[i+1] == s[i+2])){
            return false;
        }
    }

    return true;
}

void solve(){
    string s;
    cin >> s;
    bool hasL = false;
    vector<int> idx;
    int sz = s.size();
    vector<bool> a(sz, false);
    for(int i=0;i<sz;i++){
        if(s[i] == 'L'){
            hasL = true;
        }
        if(s[i] == '_'){
            idx.push_back(i);
        }
        a[i] = isVowel(s[i]);
    }
    int n = idx.size();
    ll ans = 0;
    debug(a);
    if(hasL){
        int sum = 1 << n;
        for(int i=0;i<sum;i++){
            int tmp = i;
            int cc = 0;
            for(auto j: idx){
                a[j] = tmp & 1;
                tmp = tmp >> 1;
                cc += a[j];
            }
            if(check(a)){
                debug(a);
                ll x = 1;
                REP(j, cc) x *= 5LL;
                REP(j, n-cc) x *= 21LL;
                ans += x;
            }
        }
    } else {
        int sum = 1 << (n-1);
        debug(sum);
        int cnt = 0;
        for(auto j: idx){
            debug(j);
            a[j] = 0;
            for(int i=0;i<sum;i++){
                int tmp = i;
                int cc = 0;
                for(auto k: idx){
                    if(k != j){
                        a[k] = tmp & 1;
                        tmp = tmp >> 1;
                        cc += a[k];
                    }
                }
                if(check(a)){
                    ll x = 1;
                    debug(cnt, j);
                    ll con = 20;
                    for(auto k: idx){
                        if(k == j){
                            con = 21;
                            continue;
                        }
                        if(a[k] == 0){
                            x *= con;
                        } else {
                            x *= 5LL;
                        }
                    }
                    ans += x;
                }
            }
            cnt ++;
        }
    }
    cout << ans << endl;
}

/********** Good Luck :) **********/
int main () {
    TIME(main);
    IOS();
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }

    return 0;
}
