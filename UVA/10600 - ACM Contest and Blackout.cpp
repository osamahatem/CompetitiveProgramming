/*
 * 10600 - ACM Contest and Blackout.cpp
 *
 *  Created on: Oct 2, 2014
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

	int t;
	cin >> t;
	while (t--) {
		int n, m, u, v, c;
		vector<edge> all;
		cin >> n >> m;
		while (m--) {
			cin >> u >> v >> c;
			all.push_back(edge { u, v, c });
		}
		sort(all.begin(), all.end());
		disjointSet DS(n);
		int a1 = 0, a2 = 1 << 28;
		vector<int> ans;
		for (int i = 0; i < (int) all.size(); i++)
			if (DS.merge(all[i].u, all[i].v))
				a1 += all[i].c, ans.push_back(i);
		for (int j = 0; j < (int) ans.size(); j++) {
			disjointSet DS1(n);
			int temp = 0;
			for (int i = 0; i < (int) all.size(); i++)
				if (i == ans[j])
					continue;
				else if (DS1.merge(all[i].u, all[i].v))
					temp += all[i].c;
			int r = DS1.find(1);
			for (int i = 2; i <= n; i++)
				if (DS1.find(i) != r)
					goto skip;
			a2 = min(a2, temp);
			skip: ;
		}
		cout << a1 << " " << a2 << "\n";
	}
	return 0;
}
