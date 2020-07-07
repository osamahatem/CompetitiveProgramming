/*
 * 501C. Misha and Forest.cpp
 *
 *  Created on: Jun 7, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int deg[1 << 16], s[1 << 16];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n;
	cin >> n;
	queue<int> Q;
	vector<pair<int, int> > edges;
	for (int i = 0; i < n; i++) {
		cin >> deg[i] >> s[i];
		if (deg[i] == 1)
			Q.push(i);
	}
	while (Q.size()) {
		int cur = Q.front();
		Q.pop();
		if (!deg[cur])
			continue;
		deg[s[cur]]--, s[s[cur]] ^= cur;
		edges.push_back(make_pair(cur, s[cur]));
		if (deg[s[cur]] == 1)
			Q.push(s[cur]);
	}
	cout << edges.size() << endl;
	for (int i = 0; i < (int) edges.size(); i++)
		cout << edges[i].first << " " << edges[i].second << endl;
	return 0;
}
