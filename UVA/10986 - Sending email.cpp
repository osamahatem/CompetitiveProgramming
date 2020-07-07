/*
 * 10986 - Sending email.cpp
 *
 *  Created on: Oct 10, 2014
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 2e5 + 5;
const int MAXE = 1e6 + 5;

int head[MAXN], nxt[MAXE], to[MAXE], cost[MAXE], last;
bool vis[MAXN];
int src, tar;

void init() {
	memset(head, -1, sizeof head);
	memset(vis, 0, sizeof vis);
	last = 0;
}

void addEdge(int f, int t, int c) {
	nxt[last] = head[f];
	to[last] = t;
	cost[last] = c;
	head[f] = last++;
}

void addBiEdge(int f, int t, int c) {
	addEdge(f, t, c);
	addEdge(t, f, c);
}

int Dijkstra() {
	priority_queue<pair<int, int> > Q;
	Q.push(make_pair(0, src));
	int curN, curC;
	while (Q.size()) {
		curN = Q.top().second;
		curC = -(Q.top().first);
		Q.pop();
		if (curN == tar)
			return curC;
		if (vis[curN])
			continue;
		vis[curN] = 1;
		for (int i = head[curN]; i != -1; i = nxt[i]) {
			if (!vis[to[i]])
				Q.push(make_pair(-(curC + cost[i]), to[i]));
		}
	}
	return -1;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int t, tc = 0;
	cin >> t;
	while (t--) {
		init();
		int n, m, u, v, c;
		cin >> n >> m >> src >> tar;
		while (m--) {
			cin >> u >> v >> c;
			addBiEdge(u, v, c);
		}
		cout << "Case #" << ++tc << ": ";
		int ans = Dijkstra();
		if (ans == -1)
			cout << "unreachable\n";
		else
			cout << ans << "\n";
	}
	return 0;
}
