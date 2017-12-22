/*
 * 2730 - Toll.cpp
 *
 *  Created on: Dec 21, 2017
 *      Author: Osama Hatem
 */
 
/*
Perform Dijkstra from the target node with a cost equal to the items required
upon arrival. Calculate the cost increase over the edges depending on the type
of the current node.
*/

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int n, src, dest, c;
bool vis[255];
vector<int> adj[255];

int solve() {
	memset(vis, 0, sizeof vis);
	set<pair<int, int>> S;
	S.insert(make_pair(c, dest));
	while (S.size()) {
		int id = S.begin()->second, cost = S.begin()->first;
		S.erase(S.begin());
		if (vis[id])
			continue;
		vis[id] = 1;
		if (id == src)
			return cost;
		for (auto x : adj[id]) {
			if (id >= 'a' && id <= 'z') {
				S.insert(make_pair(cost + 1, x));
			} else {
				for (int i = cost + 1; i; i++) {
					if (i - (i + 19) / 20 == cost) {
						S.insert(make_pair(i, x));
						break;
					}
				}
			}
		}
	}
	return -1;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int t = 0;
	while (cin >> n, ~n) {
		for (int i = 0; i < 255; i++)
			adj[i].clear();
		string a, b;
		while (n--) {
			cin >> a >> b;
			adj[a[0]].push_back(b[0]);
			adj[b[0]].push_back(a[0]);
		}
		cin >> c >> a >> b;
		src = a[0], dest = b[0];
		cout << "Case " << ++t << ": " << solve() << endl;
	}
	return 0;
}
