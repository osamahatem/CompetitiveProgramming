/*
 * 6897 - Exploration.cpp
 *
 *  Created on: Oct 2, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int degree[2005];
bool in[2005];
vector<int> adj[2005];

struct node {
	int n;

	const bool operator <(const node &a) const {
		if (degree[n] != degree[a.n])
			return degree[n] < degree[a.n];
		return n < a.n;
	}
};

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int T;
	scanf("%d", &T);
	while (T--) {
		int n, k, f, a, b;
		scanf("%d%d%d", &n, &k, &f);
		for (int i = 1; i <= n; i++)
			in[i] = 1, degree[i] = 0, adj[i].clear();
		while (f--) {
			scanf("%d%d", &a, &b);
			degree[a]++, degree[b]++;
			adj[a].push_back(b), adj[b].push_back(a);
		}
		set<node> nodes;
		for (int i = 1; i <= n; i++)
			nodes.insert(node { i });
		while (nodes.size()) {
			node cur = *(nodes.begin());
			nodes.erase(nodes.begin());
			if (degree[cur.n] >= k)
				break;
			in[cur.n] = 0, n--;
			for (int i = 0; i < (int) adj[cur.n].size(); i++)
				if (in[adj[cur.n][i]]) {
					nodes.erase(node { adj[cur.n][i] });
					degree[adj[cur.n][i]]--;
					nodes.insert(node { adj[cur.n][i] });
				}
		}
		printf("%d\n", n);
	}
	return 0;
}
