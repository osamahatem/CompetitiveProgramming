/*
 * 11463 - Commandos.cpp
 *
 *  Created on: Oct 10, 2014
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int dist[105][105];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int t, tc = 0;
	cin >> t;
	while (t--) {
		int n, m, u, v;
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++)
				dist[i][j] = 1 << 28;
			dist[i][i] = 0;
		}
		while (m--) {
			cin >> u >> v;
			dist[u][v] = dist[v][u] = 1;
		}
		for (int k = 0; k < n; k++)
			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++)
					dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
		int s, d, ans = 0;
		cin >> s >> d;
		for (int i = 0; i < n; i++)
			ans = max(ans, dist[s][i] + dist[i][d]);
		cout << "Case " << ++tc << ": " << ans << "\n";
	}
	return 0;
}
