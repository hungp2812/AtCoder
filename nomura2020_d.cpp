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

int P[5050];
bool isf[5050];
bool hasf[5050];
int dp[5050][5050]; // dp[i][j] = number of comps after in first i free comp
int find(int x){
    return x == P[x] ? x:find(P[x]);
}

bool join(int a, int b){
    a = find(a);
    b = find(b);
    if (a == b) return false;
    if (a > b) swap(a, b);
    P[b] = a;
    return true;
}

int binpow(int a, int p, int m){
    if (p == 0) return 1;
    int t = binpow(a, p/2, m);
    int res = t*t%m;
    if (p%2) res = res*a%m;
    return res;
}

void Solve() {
    int n; cin >> n;
    for (int i = 0; i < n; i++)
        P[i] = i;
    
    int comps = n;
    int fre = 0;
    for (int i = 0, j; i < n; i++){
        cin >> j;
        if (j == -1){
            isf[i] = true;
            fre ++;
        }else{
            j --;
            if (join(i, j)){
                comps --;
            }
        }
    }
    
    int n_comps = comps - fre;
    int res = binpow(n - 1, fre, mod) * (n - n_comps) % mod; // the least val of road in each case
    
    vector<int> cnt(n, 0);
    for (int i = 0; i < n; i++){
        int a = find(i);
        cnt[a] ++;
        if (isf[i]){
            hasf[a] = true;
        }
    }
    
    vector<int> szf;
    for (int i = 0; i < n; i++){
        if (hasf[i])
            szf.pb(cnt[i]);
    }
    
    for (auto v:szf){
        res = (res + mod - ((v - 1) * binpow(n - 1, fre-1, mod)) % mod) % mod; // if a free comp connect itself
    }
    
    dp[0][0] = 1;
    for (int i = 0; i < szf.size(); i++){
        for (int c = 0; c <= i; c++){
            dp[i+1][c] = (dp[i+1][c] + dp[i][c]) % mod;
            dp[i+1][c+1] = (dp[i+1][c+1] + dp[i][c] * szf[i] % mod) % mod;
        }
    }
    
    int fact = 1;
    for (int i = 2; i <= szf.size(); ++i) {
        fact = fact * (i - 1) % mod;
        res = (res + mod - dp[szf.size()][i] * fact % mod * binpow(n - 1, fre - i, mod) % mod) % mod;
    }
    
    cout << res;
}

signed main(){
    FAST_IO;
    int TC = 1; 
	//cin >> TC;
    while(TC--) Solve();
    return 0;
}
