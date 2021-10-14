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
	FAST_IO("arc113_e.inp", "arc113_e.out");
#endif
	int testcases = 1;
	cin >> testcases;
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

#define Ptest(x) return cout << x << '\n', (void) 0;

void Hollwo_Pelw() {
	string s; cin >> s;
	int n = s.size(), cnta = 0, cntb = 0;
	for (auto c : s)
		cnta += c == 'a';
	cntb = n - cnta;
	// need no thing
	if (n <= 2) Ptest(s);
	if (cnta == 0 || cntb == 0)
		Ptest(s);
	if (cnta % 2 == 0 && s.back() == 'b'){
	// just reverse all a
		Ptest(string(cntb, 'b'));
	}
	if (s.back() == 'a'){
		int grp1 = 0, grp2 = 0, a = 0;
		for (auto c : s){
			if (c == 'a'){
				a ++; 
			}else{
				grp1 += a == 1;
				grp2 += a > 1;
				a = 0;
			}
		}
		cnta -= ((grp1 + 1) / 2 + grp2) * 2;
		Ptest(string(cntb, 'b') + string(cnta, 'a'));
	}
	// if 'a' stand near the last, reverse b is useless
	if (s[n - 2] == 'a'){
		Ptest(string(cntb - 1, 'b') + "ab");
	}
	if (s[n - 3] == 'a'){
		Ptest(string(cntb - 2, 'b') + "abb");
	}
	int grp1 = 0, grp2 = 0, a = 0, fb = -1;
	for (int i = 0; i < n; i++){
		if (s[i] == 'a'){
			a ++;
		}else{
			if (fb == -1)
				fb = i;
			grp1 += a == 1;
			grp2 += a > 1;
			a = 0;
		}
	}
	if (fb == cnta){
		// all a before b
		Ptest(string(cnta % 2, 'a') + string(cntb, 'b'));
	}
	if ((grp2 == 1 && fb < 2) || grp2 > 1)
		grp2 --; 
	else
		grp1 --;
	cnta -= ((grp1 + 1) / 2 + grp2) * 2;
	Ptest(string(cntb - 2, 'b') + string(cnta, 'a'));
	cout << endl;
}
