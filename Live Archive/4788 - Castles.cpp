/*
 * 4788 - Castles.cpp
 *
 *  Created on: Feb 17, 2018
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int n;
pair<int, int> req[105];
vector<vector<int>> adj;

pair<int, int> solve(int idx, int par) {
	pair<int, int> ans = req[idx];
	vector<pair<int, int>> temp;
	for (int ch : adj[idx])
		if (ch != par)
			temp.push_back(solve(ch, idx));

	sort(temp.begin(), temp.end(), greater<pair<int, int>>());
	for (auto p : temp) {
		int add = max(0, p.second - ans.first);
		ans.second += add;
		ans.first += add - p.second + p.first;
	}
	return ans;
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
	while (cin >> n, n) {
		for (int i = 1; i <= n; i++) {
			int x, y, z;
			cin >> x >> y >> z;
			req[i] = make_pair(max(x, y + z) - y - z, max(x, y + z));
		}

		adj.clear();
		adj.resize(n + 1);
		for (int i = 1; i < n; i++) {
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		int ans = 1e9;
		for (int i = 1; i <= n; i++)
			ans = min(ans, solve(i, 0).second);
		cout << "Case " << ++T << ": " << ans << endl;
	}
	return 0;
}
