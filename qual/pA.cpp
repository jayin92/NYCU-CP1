
// :19 <enter>
#include <bits/stdc++.h>
#include <sys/time.h>
#include <sys/resource.h>
#define X first
#define Y second
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;

void setstack(){
    // Set soft limit and hard limit to max
    const rlimit tmp {RLIM_INFINITY ,RLIM_INFINITY};
    setrlimit(RLIMIT_STACK ,&tmp);
}

int dx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
int dy[8] = {-1, -1, -1, 0, 0, 1, 1, 1};

vector<vector<bool>> a(105, vector<bool>(105));

int n, m;
int ans = 0;
bool check(int i, int j){
    if(i >= n || i < 0 || j >= m || j < 0) return false;
    else return a[i][j];
}

void finder(pii start, pii cur, pii pre, vector<pii> path){
    if(a[cur.X][cur.Y] == 0 || a[start.X][start.Y] == 0) return;
    if(start == cur){
        if(path.size() >= 2){
            ans ++;
             // cout << endl;
            for(auto i: path){
                // cout << i.X << " " << i.Y << endl;
                a[i.X][i.Y] = 0;
            }
            return;
        } 
    }

    path.push_back(cur);
    

    for(int i=0;i<8;i++){
        pii nxt = make_pair(cur.X + dx[i], cur.Y + dy[i]);
        // cout << nxt.X << " " << nxt.Y << endl;
        if(check(nxt.X, nxt.Y) && nxt != pre){
            finder(start, nxt, cur, path);
            // cout << nxt.X << " " << nxt.Y << endl;
        }
    }
}

void solve(){
    cin >> n >> m;
    char tmp;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> tmp;
            if(tmp == '.') a[i][j] = 0;
            else a[i][j] = 1;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i][j] == 1){
                vector<pii> path;
                pii start = make_pair(i, j);
                // cout << i << " " << j << endl;
                finder(start, start, make_pair(-1, -1), path);
            }
        }
    }

    cout << ans << endl;

            
}

int main(){
    #define name "pF"
    static_assert(strlen(name));
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }

    return 0;
}