/*
 * 4787 - Tracking Bio-bots.cpp
 *
 *  Created on: Feb 16, 2018
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int N, M, w, x1[1005], x2[1005], y[1005];
vector<int> rnk;
int grid[4005][4005], vis[4005][4005], id;

int getRnk(int x) {
	return lower_bound(rnk.begin(), rnk.end(), x) - rnk.begin();
}

long long solve(int r, int c) {
	if (r < 0 || c < 0 || grid[r][c] == id || vis[r][c] == id)
		return 0;
	vis[r][c] = id;
	return 1ll * (rnk[r + 1] - rnk[r]) * (rnk[c + 1] - rnk[c]) + solve(r - 1, c)
			+ solve(r, c - 1);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int T = 0;
	while (cin >> M >> N >> w, N) {
		rnk.clear();
		rnk.push_back(0);
		rnk.push_back(N - 1), rnk.push_back(N);
		rnk.push_back(M - 1), rnk.push_back(M);

		for (int i = 0; i < w; i++) {
			cin >> x1[i] >> y[i] >> x2[i] >> y[i];
			rnk.push_back(y[i]), rnk.push_back(y[i] + 1);
			rnk.push_back(x1[i]), rnk.push_back(x2[i] + 1);
		}

		sort(rnk.begin(), rnk.end());
		rnk.erase(unique(rnk.begin(), rnk.end()), rnk.end());

		id++;
		long long ans = 0;
		for (int i = 0; i < w; i++) {
			ans += x2[i] - x1[i] + 1;
			int yr = getRnk(y[i]), x1r = getRnk(x1[i]), x2r = getRnk(x2[i] + 1);
			for (int x = x1r; x < x2r; x++)
				grid[x][yr] = id;
		}
		ans += solve(getRnk(N - 1), getRnk(M - 1));
		cout << "Case " << ++T << ": " << 1ll * N * M - ans << endl;
	}
	return 0;
}
