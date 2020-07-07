/*
 * 11492 - Babel.cpp
 *
 *  Created on: Sep 14, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int N;
map<string, vector<pair<int, pair<int, string>>> > adj;
string src, tar;
char tmpa[55], tmpb[55], tmpc[55];

int dijkstra() {
	map<pair<int, string>, int> dist;
	set<pair<int, pair<int, string>>> active;
	for (int i = 0; i < 26; i++) {
		dist[ { i, src }] = 0;
		active.insert( { 0, { i, src } });
	}
	while (active.size()) {
		int letter = active.begin()->second.first;
		string cur = active.begin()->second.second;
		active.erase(active.begin());
		if (cur == tar)
			return dist[ { letter, cur }];
		for (auto ed : adj[cur]) {
			int nxtLetter = ed.first;
			if (nxtLetter == letter)
				continue;
			int curDist = dist[ { letter, cur }];
			string to = ed.second.second;
			int cost = ed.second.first;
			if (!dist.count( { nxtLetter, to }) || curDist + cost < dist[ {
					nxtLetter, to }]) {
				active.erase( { dist[ { nxtLetter, to }], { nxtLetter, to } });
				dist[ { nxtLetter, to }] = curDist + cost;
				active.insert( { curDist + cost, { nxtLetter, to } });
			}
		}
	}
	return -1;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	while (scanf("%d", &N), N) {
		adj.clear();
		scanf("%s%s", tmpa, tmpb);
		src = tmpa, tar = tmpb;
		while (N--) {
			scanf("%s%s%s", tmpa, tmpb, tmpc);
			adj[tmpa].push_back( { tmpc[0] - 'a', { strlen(tmpc), tmpb } });
			adj[tmpb].push_back( { tmpc[0] - 'a', { strlen(tmpc), tmpa } });
		}
		int ans = dijkstra();
		if (ans == -1)
			printf("impossivel\n");
		else
			printf("%d\n", ans);
	}
	return 0;
}
