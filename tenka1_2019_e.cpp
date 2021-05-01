/*
 /+===================================================+\
//+---------------------------------------------------+\\
|.|\\...>>>>>>> Hollwo_Pelw's 2nd template<<<<<<<...//|.|
\\+---------------------------------------------------+//
 \+===================================================+/
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
// I/O
#define setpre(n)           fixed << setprecision(n)
#define Ptest(x)            return cout << x << endl, (void) 0;
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

void FAST_IO(string filein = "", string fileout = ""){
    if (fopen(filein.c_str(), "r")){
        freopen(filein.c_str(), "r", stdin);
        freopen(fileout.c_str(), "w", stdout);
    }
    cin.tie(0), cout.tie(0) -> sync_with_stdio(0);
}

void Hollwo_Pelw();

signed main(){
    FAST_IO("input.inp", "output.out");
    int testcases = 1;
    // cin >> testcases;
    for (int test = 1; test <= testcases; test++){
        // cout << "Case #" << test << ": ";
        Hollwo_Pelw();
    }
    return 0;
}

// constant
const int allmod[3] = {(int) 1e9 + 7, 998244353, (int) 1e9 + 9};
const int mod = allmod[1];
const int MAXN = 1e4 + 5;
const int inf = 2e9;
const ll linf = 1e18;
// #define int long long

int a[MAXN], n, pr[MAXN];

set<int> res;

void check(int g){
    for (int i = 2; i * i <= g; i++){
        if (g % i == 0){
            res.insert(i);
            while (g % i == 0){
                g /= i;
            }
        }
    }
    if (g > 1)
        res.insert(g);
}

void Hollwo_Pelw() {
    cin >> n;
    int g = 0;
    for (int i = 0; i <= n; i++){
        cin >> a[i], pr[i] = 1;
        g = __gcd(g, abs(a[i]));
    }
    check(g);
    for (int i = 2; i <= n; i++){
        if (pr[i]) {
            for (int j = i * i; j <= n; j += i){
                pr[j] = 0;
            }
        }
    }
    for (int i = 2; i <= n; i++)
    int ans = 0;
    for (int i = 2; i <= n; i++){
        if (pr[i] && a[n] % i == 0) {
            vector<int> tmp(i - 1);
            for (int j = 0; j <= n; j++){
                tmp[j % (i - 1)] += a[j];
            }
            bool f = 1;
            for (auto x : tmp) 
                if (x % i) f = 0;
            if (f)
                res.insert(i);
        }
    }
    for (auto v : res)
        cout << v << "\n";
}
/*

./-=====>>><<<-------- DEBUG -------->>><<<=====-\.
/.................................................\
+====================== INP ======================+



+====================== OUT ======================+



+======================*****======================+
\................................................./
.\-=====>>><<<--------= END =-------->>><<<=====-/.

*/