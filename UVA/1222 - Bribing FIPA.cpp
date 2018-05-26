/*
 * 1222 - Bribing FIPA.cpp
 *
 *  Created on: May 26, 2018
 *      Author: Osama Hatem
 */

/*
 * The given cities and relations form a forest graph (a group of trees). We add
 * a dummy root and connect it to all actual roots, to have a single tree to
 * work with.
 * We can use DP to get the minimum cost to buy at least m nodes, by trying
 * different partitions of needed count on a node's children. This seems hard at
 * first, but can be easily achieved by only calling one child, letting that
 * child try different amounts, and call its next sibling with the remaining.
 * Complexity: O(N^3)
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int INF = 1 << 28;

int n, m, r, cost[205], sz[205], sibling[205], deg[205], dp[205][205];
vector<int> adj[205];
map<string, int> rnk;
stringstream ss;

void dfs(int idx, int sib) {
	sibling[idx] = sib, sz[idx] = 1;
	int last = -1;
	for (auto ch : adj[idx]) {
		dfs(ch, last);
		last = ch;
		sz[idx] += sz[ch];
	}
}

int solve(int idx, int need) {
	if (need < 1)
		return 0;
	if (idx == -1)
		return INF;

	int &ret = dp[idx][need];
	if (~ret)
		return ret;
	ret = min(cost[idx] + solve(sibling[idx], need - sz[idx]),
			solve(sibling[idx], need));
	if (adj[idx].size())
		for (int i = 0; i <= need; i++)
			ret = min(ret,
					solve(adj[idx].back(), i) + solve(sibling[idx], need - i));
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	string in;
	while (getline(cin, in), in != "#") {
		rnk.clear(), r = 0;
		memset(deg, 0, sizeof deg);
		memset(dp, -1, sizeof dp);

		ss = stringstream(in);
		ss >> n >> m;

		for (int i = 0; i <= n; i++)
			adj[i].clear();

		for (int i = 0; i < n; i++) {
			getline(cin, in);
			ss = stringstream(in);
			string from, to;
			ss >> from;
			if (!rnk.count(from))
				rnk[from] = r++;
			ss >> cost[rnk[from]];
			while (ss >> to) {
				if (!rnk.count(to))
					rnk[to] = r++;
				adj[rnk[from]].push_back(rnk[to]), deg[rnk[to]]++;
			}
		}

		for (int i = 0; i < n; i++)
			if (!deg[i])
				adj[r].push_back(i);
		cost[r] = INF;
		dfs(r, -1);
		cout << solve(r, m) << endl;
	}
	return 0;
}
