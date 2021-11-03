#include <bits/stdc++.h>
using namespace std;

const int N = 15;

int n, m, adj[N][N], cost[1 << N], dp[N][1 << N];

inline void chkmax(int &a, int b) { a = a > b ? a : b; }

signed main() {
	cin.tie(0), cout.tie(0) -> sync_with_stdio(0);

	cin >> n >> m;
	
	for (int u, v, w; m --; ) {
		cin >> u >> v >> w;
		-- u, -- v;
		adj[u][v] = adj[v][u] = w;
	}

	for (int mask = 0; mask < 1 << n; mask++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < i; j++) {
				if ((mask >> i & 1) && (mask >> j & 1))
					cost[mask] += adj[i][j];
			}
			dp[i][mask] = -1;
		}
	}

	int all = (1 << n) - 1;

	dp[0][1] = 0;
	for (int mask = 1; mask < 1 << n; mask++) {
		for (int i = 0; i < n; i++) if (~dp[i][mask]) {
			for (int j = 0; j < n; j++) {
				if (!(mask >> j & 1) && adj[i][j])
					chkmax(dp[j][mask | (1 << j)], dp[i][mask] + adj[i][j]);
			}
			int oth = all ^ mask;
			for (int sub = oth; sub; sub = (sub - 1) & oth)
				chkmax(dp[i][mask | sub], dp[i][mask] + cost[sub | (1 << i)]);
		}
	}

	cout << cost[all] - dp[n - 1][all];
}

