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

map<int, int> cnt, inv;
vector<int> prime;
bool isp[3000];
int n, grp[MAXN];

void Solve() {
    for (int i = 2; i < 3000; i++){
        isp[i] = true;
    }
    for (int i = 2; i < 3000; i++){
        if (isp[i]){
            prime.pb(i);
            for (int j = i*i; j < 3000; j += i){
                isp[j] = false;
            }
        }
    }

    cin >> n;
    for (int i = 0, x; i < n; i++){
        cin >> x;
        for (auto p:prime){
            int k = p*p*p;
            while (x % k == 0) x /= k;
        }
        if (++cnt[x] == 1){
            grp[i] = x, inv[i] = 1;
            for(auto p:prime){
                int k = p*p;
				if(k <= x && x % k == 0){
					inv[i] *= p, x /= k;
				}
				else if(x % p == 0){
					inv[i] *= k, x /= p;
				}
			}
            int xx = sqrt(x);
            if(xx * xx == x){
                inv[i] *= xx;
            }
            else{
                inv[i] *= x*x;
            }
        }
    }
    int ans = (int) (cnt[1] > 0);
    cnt[1] = 0;

    for (int i = 0; i < n; i++){
        if (grp[i]){
            ans += max(cnt[grp[i]], cnt[inv[i]]);
            cnt[grp[i]] = cnt[inv[i]] = 0;
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
/*

./-=====>>><<<-------- DEBUG -------->>><<<=====-\.
/.................................................\

+====================== INP ======================+


+====================== OUT ======================+


\................................................./
.\-=====>>><<<--------= END =-------->>><<<=====-/.
*/
