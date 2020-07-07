/*
 * 11228 - Transportation system.cpp
 *
 *  Created on: Oct 5, 2014
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

struct edge {
	int u, v;
	double c;

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
		return (root[n] == n ? n : root[n] = find(root[n]));
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

double dist(pair<int, int> a, pair<int, int> b) {
	int dx = a.first - b.first;
	int dy = a.second - b.second;
	return sqrt(dx * dx + dy * dy);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int t, tc = 0;
	cin >> t;
	while (t--) {
		int n, r;
		cin >> n >> r;
		vector<pair<int, int> > all(n);
		vector<edge> E;
		for (int i = 0; i < n; i++) {
			cin >> all[i].first >> all[i].second;
			for (int j = 0; j < i; j++)
				E.push_back(edge { i, j, dist(all[i], all[j]) });
		}
		sort(E.begin(), E.end());
		disjointSet DS(n);
		int st = 1;
		double ro = 0.0, rl = 0.0;
		for (int i = 0; i < (int) E.size(); i++)
			if (DS.merge(E[i].u, E[i].v)) {
				if (E[i].c > r) {
					st++;
					rl += E[i].c;
				} else
					ro += E[i].c;
			}
		printf("Case #%d: %d %.0f %.0f\n", ++tc, st, ro, rl);
	}
	return 0;
}
