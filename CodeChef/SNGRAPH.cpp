/*
 * SNGRAPH.cpp
 *
 *  Created on: May 31, 2017
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

class DisjointSet {
	int forests;
	vector<int> root, rank;

public:
	DisjointSet(int n) {
		for (int i = 0; i < n; i++)
			root.push_back(i), rank.push_back(0);
		forests = n;
	}

	int find(int x) {
		return (root[x] != x ? root[x] = find(root[x]) : root[x]);
	}

	void merge(int a, int b) {
		int ra = find(a), rb = find(b);
		if (ra == rb)
			return;
		if (rank[ra] < rank[rb])
			root[ra] = rb;
		else
			root[rb] = ra;
		if (rank[ra] == rank[rb])
			rank[ra]++;
		forests--;
	}

	int getForests() {
		return forests;
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
		int n, m;
		scanf("%d%d", &n, &m);
		vector<pair<int, int>> edges(m), deg(m);
		vector<int> deg_n(n, 0);
		for (int i = 0; i < m; i++) {
			scanf("%d%d", &edges[i].first, &edges[i].second);
			edges[i].first--, edges[i].second--;
			deg_n[edges[i].first]++, deg_n[edges[i].second]++;
		}
		for (int i = 0; i < m; i++) {
			deg[i].first = min(deg_n[edges[i].first], deg_n[edges[i].second]);
			deg[i].second = i;
		}
		sort(deg.begin(), deg.end(), greater<pair<int, int>>());
		int idx = 0;
		DisjointSet DS(n);
		vector<int> ans(n);
		for (int i = n - 1; ~i; i--) {
			while (idx < m && deg[idx].first > i) {
				int e = deg[idx].second;
				DS.merge(edges[e].first, edges[e].second);
				idx++;
			}
			ans[i] = DS.getForests() - 1;
		}
		for (int i = 0; i < n; i++) {
			if (i)
				printf(" ");
			printf("%d", ans[i]);
		}
		printf("\n");
	}
	return 0;
}
