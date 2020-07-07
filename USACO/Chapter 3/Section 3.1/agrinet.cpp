/*
 ID: 19semse1
 PROG: agrinet
 LANG: C++
 */
/*
 * agrinet.cpp
 *
 *  Created on: Mar 16, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

struct DisjointSet {
	vector<int> root, rank;

	DisjointSet(int n) {
		for (int i = 0; i < n; i++) {
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
//#ifndef ONLINE_JUDGE
	freopen("agrinet.in", "r", stdin);
	freopen("agrinet.out", "w", stdout);
//#endif

	int n, w, ans = 0;
	cin >> n;
	DisjointSet DS(n);
	vector<pair<int, pair<int, int> > > edges;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			cin >> w;
			if (i == j)
				continue;
			edges.push_back(make_pair(w, make_pair(i, j)));
		}
	sort(edges.begin(), edges.end());
	for (int i = 0; i < (int) edges.size(); i++)
		if (DS.merge(edges[i].second.first, edges[i].second.second))
			ans += edges[i].first;
	cout << ans << endl;
	return 0;
}
