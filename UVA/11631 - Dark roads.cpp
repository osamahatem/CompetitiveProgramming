/*
 * 11631 - Dark roads.cpp
 *
 *  Created on: Oct 5, 2014
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

struct edge {
	int u, v, c;

	const bool operator <(const edge &a) const {
		return c < a.c;
	}
};

struct disjointSet {
	vector<int> root, rank;

	disjointSet(int n) {
		for (int i = 0; i <= n; i++) {
			root.push_back(i);
			rank.push_back(0);
		}
	}

	int find(int n) {
		return (root[n] == n ? root[n] : root[n] = find(root[n]));
	}

	bool merge(int a, int b) {
		int sa = find(a);
		int sb = find(b);
		if (sa == sb)
			return false;
		if (rank[sa] < rank[sb])
			root[sa] = root[sb];
		else
			root[sb] = root[sa];
		if (rank[sa] == rank[sb])
			rank[sa]++;
		return true;
	}
};

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n, m;
	while (cin >> n >> m, n) {
		vector<edge> all;
		int u, v, c, total = 0;
		while (m--) {
			cin >> u >> v >> c;
			total += c;
			all.push_back(edge { u, v, c });
		}
		sort(all.begin(), all.end());
		disjointSet DS(n);
		for (int i = 0; i < (int) all.size(); i++)
			if (DS.merge(all[i].u, all[i].v))
				total -= all[i].c;
		cout << total << "\n";
	}
	return 0;
}
