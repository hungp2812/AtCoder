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
#define int long long
const int MX = 20;
int dp[MX][1 << MX], cost[1 << MX], adj[MX][MX];
int n, m;

void Solve() {
    cin >> n >> m;
    for (int i = 1, u, v, w; i <= m; i++){
        cin >> u >> v >> w;
        u --; v --;
        adj[u][v] = adj[v][u] = w;
    }
    for (int mask = 1; mask < (1 << n); mask++){
        for (int i = 0; i < n; i++){
            for (int j = i+1; j < n; j++){
                if (((mask >> i) & 1) && ((mask >> j) & 1)){
                    cost[mask] += adj[i][j];
                }
            }
            dp[i][mask] = -1;
        }
        //cout << cost[mask] << endl;
    }
    dp[0][1] = 0;
    for (int mask = 1; mask < (1 << n); mask ++){
        for (int i = 0; i < n; i++){
            if (dp[i][mask] != -1){
                for (int j = 0; j < n; j++){
                    if (!((mask >> j) & 1) && adj[i][j]){
                        dp[j][mask | (1 << j)] = max(dp[j][mask | (1 << j)], dp[i][mask] + adj[i][j]);
                    }
                }
                int left = ((1 << n) - 1) ^ mask;
                for (int nxt = left; nxt > 0; nxt = (nxt - 1) & left){
                    dp[i][mask | nxt] = max(dp[i][mask | nxt], dp[i][mask] + cost[nxt | (1 << i)]);
                }
            }
        }
    }
    cout << cost[(1 << n) - 1] - dp[n-1][(1 << n) - 1];
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
