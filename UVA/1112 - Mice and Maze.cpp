/*
 * 1112 - Mice and Maze.cpp
 *
 *  Created on: Oct 2, 2014
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

	int tc;
	cin >> tc;
	while (tc--) {
		int n, e, t, m;
		cin >> n >> e >> t >> m;
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= n; j++)
				dist[i][j] = 1 << 28;
			dist[i][i] = 0;
		}
		int u, v, c;
		while (m--) {
			cin >> u >> v >> c;
			dist[u][v] = c;
		}
		for (int k = 1; k <= n; k++)
			for (int i = 1; i <= n; i++)
				for (int j = 1; j <= n; j++)
					dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
		int ans = 0;
		for (int i = 1; i <= n; i++)
			if (dist[i][e] <= t)
				ans++;
		cout << ans << "\n";
		if (tc)
			cout << "\n";
	}
	return 0;
}
