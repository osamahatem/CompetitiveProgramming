/*
 * 377. Taxi.cpp
 *
 *  Created on: Oct 22, 2014
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXP = 402;
const int MAXT = 202;
const int L = 200;
const int MAXN = MAXP + MAXT;
const int MAXE = MAXP * MAXT;
const int SRC = MAXN - 1;
const int SNK = MAXN - 2;

int head[MAXN], to[MAXE], cap[MAXE], nxt[MAXE], last;
bool vis[MAXN];

void init() {
	last = 0;
	memset(head, -1, sizeof head);
}

void addEdge(int f, int t, long long c = 0) {
	nxt[last] = head[f];
	to[last] = t;
	cap[last] = c;
	head[f] = last++;
}

void addAugEdge(int f, int t, long long c) {
	addEdge(f, t, c);
	addEdge(t, f);
}

bool DFS(int cur) {
	if (cur == SNK)
		return true;
	vis[cur] = 1;
	for (int i = head[cur]; i != -1; i = nxt[i]) {
		if (!vis[to[i]] && cap[i] && DFS(to[i])) {
			cap[i] = 0;
			cap[i ^ 1] = 1;
			return true;
		}
	}
	return false;
}

int maxFlow() {
	int ans = 0;
	while (DFS(SRC)) {
		ans++;
		memset(vis, 0, sizeof vis);
	}
	return ans;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int T;
	cin >> T;
	while (T--) {
		init();
		int p, t, s, tm, x, y;
		cin >> p >> t >> s >> tm;
		tm *= s;
		vector<pair<int, int> > ps(p);
		for (int i = 0; i < p; i++) {
			cin >> ps[i].first >> ps[i].second;
			addAugEdge(t + i, SNK, 1);
		}
		for (int i = 0; i < t; i++) {
			cin >> x >> y;
			addAugEdge(SRC, i, 1);
			for (int j = 0; j < p; j++) {
				int dx = abs(x - ps[j].first);
				int dy = abs(y - ps[j].second);
				if ((dx + dy) * L <= tm)
					addAugEdge(i, t + j, 1);
			}
		}
		cout << maxFlow() << endl;
	}
	return 0;
}
