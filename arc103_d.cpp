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
#define open(file, in, out) if (fopen(file in, "r")) {        \
                                freopen(file in, "r", stdin);  \
                                freopen(file out, "w", stdout); \
                            }
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
/*
 *             4
 *           4   4
 *         4   2   4
 *       4   2   2   4
 *     4   2   1   2   4
 *   4   2   1 0 1   2   4
 *     4   2   1   2   4
 *       4   2   2   4
 *         4   2   4
 *           4   4
 *             4
 */

pii proc[1001];
void Solve() {
    bool odd = false, even = false;
    int n; cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> proc[i].F >> proc[i].S;
        if ((proc[i].F + proc[i].S) % 2 == 0){
            even = true;
        }else{
            odd = true;
        }
    }
    if (odd && even){
        cout << -1;
        return;
    }

    int h = 31;

    if (even) cout << h+1 << endl << 1 << ' ';
    else cout << h << endl;
    for (int i = 1; i <= (1 << 30); i*=2)
        cout << i << ' ';
    cout << endl;

    for (int tmp = 1; tmp <= n; tmp ++){
        int x = proc[tmp].F, y = proc[tmp].S;
        int p = 1ll << 30;
        string ans = "";
        while(p){
            if (abs(x) > abs(y)){
                if (x > 0){
                    x -= p;
                    ans = 'R' + ans;
                }else{
                    x += p;
                    ans = 'L' + ans;
                }
            }else{
                if (y > 0){
                    y -= p;
                    ans = 'U' + ans;
                }else{
                    y += p;
                    ans = 'D' + ans;
                }
            }
            //cout << "#" << p << ": " << x << ' ' << y << endl;
            p >>= 1;
        }
        if (x > 0) ans = 'R' + ans;
        if (x < 0) ans = 'L' + ans;
        if (y > 0) ans = 'U' + ans;
        if (y < 0) ans = 'D' + ans;
        cout << ans << endl;
        //cout << x << ' ' << y << endl;
    }

}

signed main(){
    open("", ".inp", ".out");
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

