/*
 * 366D. Dima and Trap Graph.cpp
 *
 *  Created on: Aug 24, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1e3 + 5;
const int MAXE = 6e3 + 5;

int n, m, ans = 0;
int head[MAXN], to[MAXE], nxt[MAXE], l[MAXE], r[MAXE], last;
set<pair<pair<int, int>, int>> vis;

void addEdge(int f, int t, int ll, int rr) {
	to[last] = t;
	l[last] = ll, r[last] = rr;
	nxt[last] = head[f];
	head[f] = last++;
}

void addBiEdge(int f, int t, int ll, int rr) {
	addEdge(f, t, ll, rr);
	addEdge(t, f, ll, rr);
}

void BFS() {
	queue<pair<pair<int, int>, int>> Q;
	Q.push(make_pair(make_pair(0, 1 << 20), 1));
	while (Q.size()) {
		int cur = Q.front().second, ll = Q.front().first.first, rr =
				Q.front().first.second;
		Q.pop();
		if (cur == n) {
			ans = max(ans, rr - ll + 1);
			continue;
		}
		for (int i = head[cur]; i != -1; i = nxt[i]) {
			int nl = max(ll, l[i]), nr = min(rr, r[i]);
			if (nr < nl || nr - nl + 1 < ans
					|| vis.count(make_pair(make_pair(nl, nr), to[i])))
				continue;
			vis.insert(make_pair(make_pair(nl, nr), to[i]));
			Q.push(make_pair(make_pair(nl, nr), to[i]));
		}
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	memset(head, -1, sizeof head);
	cin >> n >> m;
	int u, v, ll, rr;
	while (m--) {
		cin >> u >> v >> ll >> rr;
		addBiEdge(u, v, ll, rr);
	}
	BFS();
	if (ans)
		cout << ans << endl;
	else
		cout << "Nice work, Dima!" << endl;
	return 0;
}
