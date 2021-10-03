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
const int MAXN = 100005, MAXM = 200010;
// code
#define int long long

int pref[MAXM];

int range(int l, int r){
    return pref[r] - pref[l-1];
}
void Solve() {
    int n; cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> pref[i];
        pref[i] += pref[i-1];
    }
    int l, r, p1, p2;
    int ans = 1e18;
    for (int i = 1; i <= n; i++){
        l = 1, r = i, p1 = 1;
        while (l <= r){
            int x = (l+r)/2;
            if (range(1, x)*2 <= range(1, i)){
                l = x+1;
                p1 = x;
            }else{
                r = x-1;
            }
        }
        
        l = i+1, r = n, p2 = i+1;
        while (l <= r){
            int x = (l+r)/2;
            if (range(i+1, x)*2 <= range(i+1, n)){
                l = x+1;
                p2 = x;
            }else{
                r = x-1;
            }
        }
        
        for (int j = p1-5; j <= p1+5; j++){
            for (int k = p2-5; k <= p2+5; k++){
                if (j <= i && i <= k){
                    int A = range(1, j);
                    int B = range(j+1, i);
                    int C = range(i+1, k);
                    int D = range(k+1, n);
                    
                    ans = min(ans, max({A, B, C, D}) - min({A, B, C, D}));
                }
            }
        }
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
