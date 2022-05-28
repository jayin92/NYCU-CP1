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

int cross(pii o, pii a, pii b){
    int u = a.X - o.X;
    int v = a.Y - o.Y;
    int s = b.X - o.X;
    int t = b.Y - o.Y;

    return u * t - s * v;
}

bool cmp(pii &a, pii &b){
    return (a.X < b.X) || (a.X == b.X && a.Y < b.Y);
}

void solve(int n){
    vector<pii> a;
    set<pii> s;
    int x, y;
    for(int i=0;i<n;i++){
        cin >> x >> y;
        s.insert({x, y});
    }
    for(auto i: s){
        a.push_back(i);
    }
    n = a.size();
    if(n <= 2){
        cout << n << endl;
        for(auto i: a){
            cout << i.X << " " << i.Y << endl;
        }
        return;
    }
    sort(ALL(a), cmp);
    debug(a);
    debug(a);
    int idx = 0;
    vector<pii> ch(2*n);
    for(int i=0;i<n;i++){
        while(idx >= 2 && cross(ch[idx-2], ch[idx-1], a[i]) <= 0){
            idx --;
        }
        ch[idx++] = a[i];

    }
    for(int i=n-2,t=idx+1;i>=0;i--){
        while(idx >= t && cross(ch[idx-2], ch[idx-1], a[i]) <= 0){
            idx --;
        }
        ch[idx++] = a[i];
    }
    idx --;
    cout << idx << endl;
    for(int i=0;i<idx;i++){
        cout << ch[i].X << " " << ch[i].Y << endl;
    }

}



/********** Good Luck :) **********/
int main () {
    TIME(main);
    IOS();
    int n;
    
    while(cin >> n){
        if(n == 0) break;
        solve(n);
    }

    return 0;
}
