#include <bits/stdc++.h>
using namespace std;
// type
#define int long long
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
const int mod1 = 998244353, p = 1e9+7;
const int MAX_N = 100005, MAX_M = 200010;
// code
int n, m, s;
int pref[MAX_N], suff[MAX_N], a[MAX_N], b[MAX_N], c[MAX_N];
int prefans[MAX_N], suffans[MAX_N];
void Solve() {
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        b[i] = c[i] = a[i];
    }

    for (int i = 0; i < n; i++){
        pref[i] = 0;
        if (i == 0)
            continue;
        while (b[i] < b[i-1]){
            pref[i] += 2;
            b[i] *= 4;
        }
    }
    m = pref[n-1], s = 0;
    for (int i = n-1; i >= 0; i--){
        m = min(pref[i], m); s += pref[i];
        prefans[i] = s - m*(n-i);
    }

    for (int i = n-1; i >= 0; i--){
        suff[i] = 0;
        if (i == n-1)
            continue;
        while (c[i] < c[i+1]){
            suff[i] += 2;
            c[i] *= 4;
        }
    }
    m = suff[0], s = 0;
    for (int i = 0; i < n; i++){
        m = min(suff[i], m); s += suff[i];
        suffans[i] = s - m*(n-i);
    }
    int ans = INT_MAX;
    for (int i = 0; i <= n; i++){
        ans = min(suffans[i] + prefans[i], ans);
    }
	cout << ans;
}


signed main(){
    FAST_IO;
    int TC = 1;
	//cin >> TC;
    while(TC--) Solve();
    return 0;
}
