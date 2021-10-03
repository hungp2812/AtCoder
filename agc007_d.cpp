#include <bits/stdc++.h>
using namespace std;
// type
typedef long long ll;
typedef long double ld;
// loop
//#define For(i, l, r, x)     for (int i = l; i < r; i+=x)
//#define ForE(i, l, r, x)    for (int i = l; i <= r; i+=x)
//#define Ford(i, r, l)       for (int i = r; i > l; i--)
//#define FordE(i, r, l)      for (int i = r; i >= l; i--)
//#define Fora(i, a)          for (auto i : a)
// I/O 
#define FAST_IO             std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
//#define PrintV(a)           Fora(ii, a) cout << ii << ' '; cout << rl;
//#define PrintVl(a)          Fora(ii, a) cout << ii << rl;
//#define PrintA(a, l, r)     for (int ii = l; ii <= r; ii++) cout << a[ii] << ' '; cout << rl;
//#define PrintAl(a, l, r)    for (int ii = l; ii <= r; ii++) cout << a[ii] << rl;
//#define Ptest(x)            return cout << x, 0;
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
// geometry calc    
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
const int MAXN = 100005, MAX_M = 200010;
// code
#define int long long
int n, x[MAXN], dp[MAXN], e, t;
int seg[2][4*MAXN];

void build(int p, int v, int tl, int tr) {
    if (tl == tr) {
        seg[p][v] = 0;
    } else {
        int tm = (tl + tr) / 2;
        build(p, v*2, tl, tm);
        build(p, v*2+1, tm+1, tr);
        seg[p][v] = min(seg[p][v*2], seg[p][v*2+1]);
    }
}

void upd(int p, int v, int tl, int tr, int pos, int val) {
    if (tl == tr) {
        seg[p][v] = val;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            upd(p, v*2, tl, tm, pos, val);
        else
            upd(p, v*2+1, tm+1, tr, pos, val);
        seg[p][v] = min(seg[p][v*2], seg[p][v*2+1]);
    }
}

int query(int p, int v, int tl, int tr, int l, int r) {
    if (l > r) 
        return 1e18;
    if (l == tl && r == tr) {
        return seg[p][v];
    }
    int tm = (tl + tr) / 2;
    return min(query(p, v*2, tl, tm, l, min(r, tm)),
            query(p, v*2+1, tm+1, tr, max(l, tm+1), r));
}

void Solve() {
	cin >> n >> e >> t; 
	for (int i = 1; i <= n; i++)
		cin >> x[i];
    
	build(0, 0, 0, n);
	build(1, 0, 0, n);
	
	int K = 0;
	for (int i = 1; i <= n; i++){
        /*
        dp[i] = 1e18;
        for (int j = 0; j < i; j++) 
            dp[i] = min(dp[i], dp[j] + max(2 * (x[i] - x[j+1]), t));
        
        if found smallest K (use bin_search or two-pointer) that 2 * (x[i] - x[K+1]) <= t
        for j in range [0..K): dp[i] = dp[j] - 2 * x[j+1] + 2 * x[i];
        for j in range [K..i): dp[i] = dp[j] + t;
        
        // build segment tree to get minimum value in range of dp[j] - 2 * x[j+1] && d[j];
        */
		upd(0, 0, 0, n, i-1, dp[i-1]);
		upd(1, 0, 0, n, i-1, dp[i-1] - 2*x[i]);
		cout << "UDP 0: " << query(0, 0, 0, n, i-1, i-1) << endl;
		cout << "UDP 1: " << query(1, 0, 0, n, i-1, i-1) << endl;
        /*
        int l = 0, r = i-1, K = i-1;
        while (l <= r){
            int m = (l+r)/2;
            if (2 * (x[i] - x[m+1]) <= t){
                K = m;
                r = m-1;
            }else{
                l = m+1;
            }
        }
        */
		while (2*(x[i] - x[K+1]) > t) K++;
        
		dp[i] = min(query(1, 0, 0, n, 0, K-1) + 2*x[i],
					query(0, 0, 0, n, K, i-1) + t);
        
		cout << t << ' ' << K << "\n";
		cout << "seg0 " << query(0, 0, 0, n, K, i) + t << endl;
		cout << "seg1 " << query(1, 0, 0, n, 0, K-1) + 2*x[i] << endl;
		cout << "dp   " << dp[i] << endl << endl;
		
	}
	
	cout << dp[n] + e;
}

signed main(){
	FAST_IO;
	int TC = 1;
	//cin >> TC;
	while(TC--) Solve();
	return 0;
}
