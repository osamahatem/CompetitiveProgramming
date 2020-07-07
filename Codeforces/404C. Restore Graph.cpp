/*
 * 404C. Restore Graph.cpp
 *
 *  Created on: Jun 13, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1e5 + 5;

pair<int, int> d[MAXN];
int deg[MAXN];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> d[i].first;
		d[i].second = i + 1;
	}
	sort(d, d + n);
	if (d[0].first != 0) {
		cout << "-1" << endl;
		return 0;
	}
	vector<pair<int, int> > edges;
	int from = 0;
	for (int to = 1; to < n; to++) {
		if (d[from].first + 1 > d[to].first || from == to) {
			cout << "-1" << endl;
			return 0;
		}
		if (d[from].first + 1 < d[to].first || deg[d[from].second] == k) {
			from++;
			to--;
			continue;
		}
		edges.push_back(make_pair(d[from].second, d[to].second));
		deg[d[from].second]++, deg[d[to].second]++;
	}
	cout << edges.size() << endl;
	for (int i = 0; i < (int) edges.size(); i++)
		cout << edges[i].first << " " << edges[i].second << endl;
	return 0;
}
