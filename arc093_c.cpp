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
// I/O
#define open(file, in, out) if (fopen(file in, "r")) {        \
                                freopen(file in, "r", stdin);  \
                                freopen(file out, "w", stdout); \
                            }
#define FAST_IO             std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define setpre(n)           fixed << setprecision(n)
bool endline = false;
template<class T>
istream& operator >> (istream& inp, vector<T>& v){
    for (auto& it : v) inp >> it;
    return inp;
}
template<class T>
ostream& operator << (ostream& out, vector<T>& v){
    for (auto& it : v) out << it << (endline ? "\n" : " ");
    return out;
}
template<class T, class U>
istream& operator >> (istream& inp, pair<T, U>& v){
    inp >> v.F >> v.S;
    return inp;
}
template<class T, class U>
ostream& operator << (ostream& out, pair<T, U>& v){
    out << v.F << ' ' << v.S;
    return out;
}
#define debug(x)            cout << #x << " : " << x << endl;
#define Ptest(x)            return cout << x << endl, (void) 0;
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
const int mod1 = 998244353, mod = 1e9 + 7;
const int MAXN = 2e5 + 5 , MAXM = 3e5 + 5;
const int inf = 2e9; const ll linf = 1e18;
// code
#define left node << 1, tl, tm
#define right node << 1 | 1, tm + 1, tr
#define int long long

int binpow(int a, int x){
    int r = 1;
    while(x){
        if (x & 1) r = r * a % mod;
        a = a * a % mod; x >>= 1;
    }
    return r;
}

int n, m, X, D, P[MAXN];
// union-find to find MST
int find(int u){
    return P[u] = (P[u] == u ? u : find(P[u]));
}

bool join(int u, int v){
    u = find(u), v = find(v);
    if (u == v)
        return 0;
    P[u] = v;
    return 1;
}

struct Edge {
    int u, v, w;
    Edge(int _u, int _v, int _w)
        : u(_u), v(_v), w(_w) {

    }
    bool operator < (const Edge &oth) const {
        return w < oth.w;
    }
    int nxt(int x){
        return x ^ u ^ v;
    }
};

vector<Edge> edges, query;

vector<int> adj[MAXN];
int par[MAXN][18];
int mx[MAXN][18];
int dep[MAXN];

void build_lca(int u, int ff = -1){
    int p, w;
    if (ff == -1){
        p = 0;
        w = -inf;
    }else{
        p = edges[ff].nxt(u);
        w = edges[ff].w;
    }
    par[u][0] = p;
    mx[u][0] = w;
    for (int i = 1, v; i <= 17; i++){
        v = par[u][i - 1]; par[u][i] = par[v][i - 1];
        mx[u][i] = max(mx[u][i - 1], mx[v][i - 1]);
    }
    for (auto i : adj[u]){
        int v = edges[i].nxt(u);
        if (v != p){
            dep[v] = dep[u] + 1;
            build_lca(v, i);
        }
    }
}

int find_lca(int u, int v){
    int res = -inf;
    if (dep[v] > dep[u]) swap(u, v);
    for (int i = 17; i >= 0; i--){
        if (dep[par[u][i]] < dep[v])
            continue;
        res = max(res, mx[u][i]);
        u = par[u][i];
    }
    if (u == v) return res;
    for (int i = 17; i >= 0; i--){
        if (par[u][i] != par[v][i]){
            res = max(res, mx[u][i]);
            u = par[u][i];
            res = max(res, mx[v][i]);
            v = par[v][i];
        }
    }
    res = max(res, mx[u][0]);
    res = max(res, mx[v][0]);
    return res;
}

void print_lca(){
    for (int i = 1; i <= n; i++){
        for (int j = i + 1; j <= n; j++){
            cout << i << ' ' << j << endl;
            debug(find_lca(i, j));
        }
    }
}

void Solve() {
    cin >> n >> m >> X;
    // find MST
    for (int i = 1; i <= n; i++)
        P[i] = i;
    for (int i = 1, u, v, w; i <= m; i++){
        cin >> u >> v >> w;
        edges.eb(u, v, w);
    }
    sort(all(edges));
    for (int i = 0; i < edges.size(); i++){
        int u = edges[i].u;
        int v = edges[i].v;
        int w = edges[i].w;
//        cout << u << ' ' << v << ' ' << w << endl;
        if (join(u, v)){
            D += w;
            adj[u].pb(i);
            adj[v].pb(i);
//            cout << u << ' ' << v << ' ' << w << endl;
        }else{
            query.pb(edges[i]);
        }
    }
    if (X < D) Ptest(0);
//    cout << D << endl;
    X -= D;
//    build lca for MST
    build_lca(1);
//    print_lca();
    int up = 0, lw = 0, eq = 0;
    for (auto ed : query){
        int u = ed.u, v = ed.v, w = ed.w;
//        cout << u << ' ' << v << ' ' << w << endl;
        int diff = w - find_lca(u, v);
        if (diff == X){
            eq ++;
        }else if (diff < X){
            lw ++;
        }else{
            up ++;
        }
    }
//    cout << lw << ' ' << eq << ' ' << up << endl;
    int ans = (binpow(2, eq) + mod - 1) % mod * binpow(2, up + 1);
    if (!X){
        ans += (binpow(2, n - 1) + mod - 2) % mod * binpow(2, m - n + 1);
    }
    cout << ans % mod << endl;
}

signed main(){
    open("", ".inp", ".out");
    FAST_IO; int TC = 1;
//    cin >> TC;
    while(TC--) Solve();
    return 0;
}
/*

\/-=====>>><<<-------- DEBUG -------->>><<<=====-\/
/\.............................................../\
+====================== INP ======================+


+====================== OUT ======================+


+======================*****======================+
\/...............................................\/
/\-=====>>><<<--------= END =-------->>><<<=====-/\

*/
