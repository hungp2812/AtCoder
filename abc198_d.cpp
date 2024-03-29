/*
 /+===================================================+\
//+---------------------------------------------------+\
|.|\...>>>>>>> Hollwo_Pelw's 2nd template<<<<<<<...//|.|
\+---------------------------------------------------+//
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
void debug(){
    cout << endl;
}
template <typename H, typename... T>
void debug(H a, T... b){
    cout << a << ' ';
    debug(b...);
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
    #ifdef hollwo_pelw_local
        FAST_IO("input.inp", "output.out");
        auto start = chrono::steady_clock::now();
    #else
        FAST_IO(".inp", ".out");
    #endif
    int testcases = 1;
    // cin >> testcases;
    for (int test = 1; test <= testcases; test++){
        // cout << "Case #" << test << ": ";
        Hollwo_Pelw();
    }
    #ifdef hollwo_pelw_local
        auto end = chrono::steady_clock::now();
        cout << endl;
        cout << "Excution time : " << chrono::duration_cast<chrono::milliseconds> (end - start).count() << "[ms]" << endl;
    #endif
    return 0;
}

// constant
const int allmod[3] = {(int) 1e9 + 7, 998244353, (int) 1e9 + 9};
const int mod = allmod[0];
const int MAXN = 1010;
const int inf = 2e9;
const ll linf = 1e18;
#define int long long

string p, q, r;

int occ[26], cnt;

int x, y, z;
int val[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

void Hollwo_Pelw() {
    for (int i = 0; i < 26; i++)
        occ[i] = -1;
    cin >> p >> q >> r;
    for (auto v : p){
        if (occ[v - 'a'] == -1)
            occ[v - 'a'] = cnt ++;
    }
    for (auto v : q){
        if (occ[v - 'a'] == -1)
            occ[v - 'a'] = cnt ++;
    }
    for (auto v : r){
        if (occ[v - 'a'] == -1)
            occ[v - 'a'] = cnt ++;
    }
    if (cnt > 10) Ptest("UNSOLVABLE");
    do {
        if (val[occ[p[0] - 'a']] == 0)
            continue;
        if (val[occ[q[0] - 'a']] == 0)
            continue;
        if (val[occ[r[0] - 'a']] == 0)
            continue;
        x = 0;
        for (auto v : p)
            x = x * 10 + val[occ[v - 'a']];
        y = 0;
        for (auto v : q)
            y = y * 10 + val[occ[v - 'a']];
        z = 0;
        for (auto v : r)
            z = z * 10 + val[occ[v - 'a']];
        if (x + y == z){
            cout << x << '\n' << y << '\n' << z;
            return ;
        }
    } while(next_permutation(val, val + 10));
    Ptest("UNSOLVABLE");
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