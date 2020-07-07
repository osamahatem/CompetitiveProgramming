/*
 ID: 19semse1
 PROG: comehome
 LANG: C++
 */
/*
 * comehome.cpp
 *
 *  Created on: Mar 15, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

map<char, vector<pair<char, int> > > adj;
set<char> vis;

pair<char, int> Dijkstra() {
	priority_queue<pair<int, char> > Q;
	Q.push(make_pair(0, 'Z'));
	while (Q.size()) {
		char c = Q.top().second;
		int d = -Q.top().first;
		Q.pop();
		if (vis.count(c))
			continue;
		if (isupper(c) && c != 'Z')
			return make_pair(c, d);
		vis.insert(c);
		for (int i = 0; i < (int) adj[c].size(); i++)
			Q.push(make_pair(-d - adj[c][i].second, adj[c][i].first));
	}
	return make_pair('Z', 0);
}

int main() {
//#ifndef ONLINE_JUDGE
	freopen("comehome.in", "r", stdin);
	freopen("comehome.out", "w", stdout);
//#endif

	int p, d;
	char a, b;
	cin >> p;
	while (p--) {
		cin >> a >> b >> d;
		adj[a].push_back(make_pair(b, d));
		adj[b].push_back(make_pair(a, d));
	}
	pair<char, int> ans = Dijkstra();
	cout << ans.first << " " << ans.second << endl;
	return 0;
}
