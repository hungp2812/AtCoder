/*
// is short or still long ???
hollwo_pelw's template(short)
// Note : -Dhollwo_pelw_local
*/

#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/trie_policy.hpp>
// #include <ext/rope>

using namespace std;
// using namespace __gnu_pbds;
// using namespace __gnu_cxx;

void FAST_IO(string filein = "", string fileout = "", string fileerr = ""){
	if (fopen(filein.c_str(), "r")){
		freopen(filein.c_str(), "r", stdin);
		freopen(fileout.c_str(), "w", stdout);
#ifdef hollwo_pelw_local
		freopen(fileerr.c_str(), "w", stderr);
#endif
	}
	cin.tie(0), cout.tie(0) -> sync_with_stdio(0);
}

void Hollwo_Pelw();

signed main(){
#ifdef hollwo_pelw_local
	FAST_IO("input.inp", "output.out", "error.err");
	auto start = chrono::steady_clock::now();
#else
	FAST_IO("arc104_e.inp", "arc104_e.out");
#endif
	int testcases = 1;
	// cin >> testcases;
	for (int test = 1; test <= testcases; test++){
		// cout << "Case #" << test << ": ";
		Hollwo_Pelw();
	}
#ifdef hollwo_pelw_local
	auto end = chrono::steady_clock::now();
	cout << "\nExcution time : " << chrono::duration_cast<chrono::milliseconds> (end - start).count() << "[ms]" << endl;
#endif
	return 0;
}

const int N = 10, mod = 1e9 + 7;

#define defop(type, op) \
	friend inline type operator op (type a, const type &b) { return a op##= b; } \
	type& operator op##= (const type &oth)

template<int mod> struct mod_int {
	int v;
	mod_int(long long _v = 0) 
		: v(norm(_v)) {}
	
	inline int norm(long long a) {
		return a < 0 ? a % mod + mod : a % mod;
	}
	mod_int neg() const { return v == 0 ? 0 : mod - v; }
	
	template <typename T>
	explicit operator T() const { return v; }	

	mod_int operator - () const { return neg(); }
	mod_int operator + () const { return mod_int(*this); }

	mod_int& operator -- () { if (v == 0) v = mod; -- v; return *this; }
	friend mod_int operator -- (mod_int& a, int) { mod_int r = a; --a; return r; }
	mod_int& operator ++ () { ++ v; if (v == mod) v = 0; return *this; }
	friend mod_int operator ++ (mod_int& a, int) { mod_int r = a; ++a; return r; }
	
	defop(mod_int, +) {
		if ((v += oth.v) >= mod) v -= mod;
		return *this;
	}
	defop(mod_int, -) {
		if ((v -= oth.v) < 0) v += mod;
		return *this;
	}
	defop(mod_int, *) {
		return *this = norm(1ll * v * oth.v);
	}

	mod_int pow(long long b) const {
		mod_int a = *this, r = 1;
		while (b) {
			if (b&1) r *= a;
			b >>= 1; a *= a;
		}
		return r;
	}
	mod_int inv() const { return pow(mod - 2); }

	defop(mod_int, /) { 
		return *this *= oth.inv();
	}

	friend std::ostream& operator << (std::ostream& out, const mod_int& n) { return out << int(n); }
	friend std::istream& operator >> (std::istream& inp, mod_int& n) { long long x; inp >> x; n = mod_int(x); return inp; }
};

using Mint = mod_int<mod>;

Mint tot_ways = 1, res;
int n, a[N], b[N], chk[N], lis[N];

bool __get_mask(int mask) {
	for (int i = 0; i < n; i++)
		b[i] = mask % n, mask /= n;

	// check if simplest form
	memset(chk, 0, sizeof chk);
	for (int i = 0; i < n; i++)
		chk[b[i]] = 1;
	for (int i = 0; i < n; i++)
		if (!chk[i] && chk[i + 1]) return 0;
	return 1;
}

int __get_lis() {
	lis[0] = 1;
	for (int i = 1; i < n; i++) {
		lis[i] = 1;
		for (int j = 0; j < i; j++)
			if (b[j] < b[i])
				lis[i] = max(lis[i], lis[j] + 1);
	}
	return *max_element(lis, lis + n);
}

Mint C(int n, int k) {
	if (k > n || k < 0) return 0;
	Mint res = 1;
	for (int i = n, j = 1; j <= k; j++, i--)
		res = res * i / j;
	return res;
}


Mint dp[N][N];

Mint solve(vector<int> bound) {
	int n = bound.size();
	for (auto v : bound)
		if (v <= 0) return 0;

	memset(dp, 0, sizeof dp);

	bound.insert(bound.begin(), 0);

	for (int i = n; i >= 1; i--) {
		for (int j = 0; j < i; j++) {
			int v = bound[i] - bound[j];
			dp[i][j] += C(v, n - i + 1);
			for (int k = n; k > i; k--)
				dp[i][j] += C(v, k - i) * dp[k][i];
		}
	}

	return dp[1][0];
}

void Hollwo_Pelw() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i], tot_ways *= a[i];

	int tot_mask = 1;
	for (int i = 0; i < n; i++)
		tot_mask = tot_mask * n;

	// generate forms
	for (int mask = 0; mask < tot_mask; mask++) {
		if (!__get_mask(mask)) continue ;
		int val = __get_lis();

		for (int i = 0; i <= n; i++) chk[i] = 2e9;
		for (int i = 0; i < n; i++)
			chk[b[i]] = min(chk[b[i]], a[i]);

		for (int i = n; i > 0; i--)
			chk[i - 1] = min(chk[i - 1], chk[i] - 1);

		vector<int> bound;
		for (int i = 0; i < n; i++)
			if (chk[i] <= 1e9) 
				bound.push_back(chk[i]);

		res += solve(bound) * val;
	}

	cout << res / tot_ways;
}
