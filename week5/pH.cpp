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
const ll MAXN = 1005;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

vector<vector<int>> a(MAXN, vector<int>(MAXN));
vector<vector<int>> dis(MAXN, vector<int>(MAXN, iNF));
int r, c;
pii dir[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

class Node{
public:
    int x;
    int y;
    int cost;
    Node(int _x, int _y, int _cost): x(_x), y(_y), cost(_cost) {}
    bool operator>(const Node& rhs) const {
        return this -> cost > rhs.cost;
    }
};

inline bool check(int x, int y){
    if(x < 0 || x >= r || y < 0 || y >= c) return false;
    return true;
}



void dijkstra(){
    priority_queue<Node, vector<Node>, greater<Node>> pq;
    for(int i=0;i<r;i++){
        dis[i][0] = a[i][0];
        pq.push(Node(i, 0, a[i][0]));
    }

    while(!pq.empty()){
        int x = pq.top().x;
        int y = pq.top().y;
        int cost = pq.top().cost;

        pq.pop();

        if(cost > dis[x][y]) continue;

        for(int i=0;i<4;i++){
            int xx = x + dir[i].X;
            int yy = y + dir[i].Y;

            if(check(xx, yy)){
                if(max(a[xx][yy], cost) < dis[xx][yy]){
                    dis[xx][yy] = max(a[xx][yy], cost);
                    pq.push(Node(xx, yy, dis[xx][yy]));
                }
            }

        }
    }
}

void solve(){
    cin >> r >> c;
    REP(i, r){
        REP(j, c){
            cin >> a[i][j];
        }
    }
    dijkstra();
    int ans = iNF;
    for(int i=0;i<r;i++){
        ans = min(ans, dis[i][c-1]);
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
