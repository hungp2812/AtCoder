/*
 /+==================================================+\
//+--------------------------------------------------+\\
|.|\\...>>>>>>> Hollwo_Pelw(ass) 's code <<<<<<<...//|.|
\\+--------------------------------------------------+//
 \+==================================================+/
*/
#include <bits/stdc++.h>
using namespace std;
// type
typedef long long ll;
typedef long double ld;
// loop
//#define For(i, l, r)        for (int i = l; i < r; i++)
//#define ForE(i, l, r)       for (int i = l; i <= r; i++)
//#define Ford(i, r, l)       for (int i = r; i > l; i--)
//#define FordE(i, r, l)      for (int i = r; i >= l; i--)
//#define Fora(i, a)          for (auto i : a)
// I/O
#define FAST_IO             std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define setpre(n)           fixed << setprecision(n)
// pair
#define F                   first
#define S                   second
#define pii                 pair<int, int>
#define pll                 pair<ll, ll>
#define pdd                 pair<ld, ld>
// vector & !!?(string)
#define eb                  emplace_back
#define pb                  push_back
#define all(a)              a.begin(), a.end()
#define rall(a)             a.rbegin(), a.rend()
#define sz(a)               a.size()
#define len(a)              a.length()
// geometry calculate
#define pi                  acos(-1.0)
#define g_sin(a)            sin(a*pi/180)
#define g_cos(a)            cos(a*pi/180)
#define g_tan(a)            tan(a*pi/180)
// set val
#define ms0(a)              memset(a,        0, sizeof(a));
#define ms1(a)              memset(a,        1, sizeof(a));
#define msn1(a)             memset(a,       -1, sizeof(a));
#define msinf(a)            memset(a, 0x3f3f3f, sizeof(a));
// constant
const int mod1 = 998244353, mod = 1e9+7;
const int MAXN = 100005, MAXM = 200010;
// code
//#define int long long
vector<int> adj[MAXN];
int num[MAXN];
pii range[MAXN];
int odd[MAXN];
int n, k;

void kill(){
    cout << "No\n";
    exit(0);
}

void Solve() {
    cin >> n;
    for (int i = 1; i <= n; i++){
        range[i] = {-1e9, 1e9};
        odd[i] = 2;
    }
    for (int i = 1, u, v; i < n; i++){
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    priority_queue<pii, vector<pii>, greater<pii>> bfs;
    cin >> k;
    for (int i = 1, v, p; i <= k; i++){
        cin >> v >> p;
        range[p].F = max(range[p].F, v);
        range[p].S = min(range[p].S, v);
        odd[p] = v % 2;
        bfs.push({0, p});
    }
    while (!bfs.empty()){
        int p = bfs.top().S;
        for (auto v:adj[p]){
            if (max(range[p].F - 1, range[v].F) > min(range[p].S + 1, range[v].S))
                kill();
            if (odd[p] == odd[v])
                kill();
            if (range[v].F == max(range[p].F - 1, range[v].F) && range[v].S == min(range[p].S + 1, range[v].S))
                continue;
            range[v].F = max(range[p].F - 1, range[v].F);
            range[v].S = min(range[p].S + 1, range[v].S);

            odd[v] = 1 - odd[p];
            bfs.push({range[v].S - range[v].F, v});
        }
    }
    cout << "Yes\n";
    for (int i = 1; i <= n; i++){
        cout << range[i].F << endl;
    }
}

signed main(){
    FAST_IO;
    int TC = 1;
    //cin >> TC;
    while(TC--) Solve();
    return 0;
}
/*

./-=====>>><<<-------- DEBUG -------->>><<<=====-\.
/.................................................\

+====================== INP ======================+


+====================== OUT ======================+


\................................................./
.\-=====>>><<<--------= END =-------->>><<<=====-/.
*/
