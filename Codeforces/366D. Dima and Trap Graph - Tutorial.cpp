/*
 * 366D. Dima and Trap Graph - Tutorial.cpp
 *
 *  Created on: Aug 25, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1e3 + 5;
const int MAXE = 6e3 + 5;

int n, m, ans = 0, bounds[MAXE];
int head[MAXN], to[MAXE], nxt[MAXE], l[MAXE], r[MAXE], last;
bool vis[MAXN];

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

bool BFS(int ll, int rr) {
	memset(vis, 0, sizeof vis);
	queue<int> Q;
	Q.push(1), vis[1] = 1;
	while (Q.size()) {
		int cur = Q.front();
		Q.pop();
		if (cur == n)
			return true;
		for (int i = head[cur]; i != -1; i = nxt[i])
			if (!vis[to[i]] && l[i] <= ll && r[i] >= rr) {
				vis[to[i]] = 1;
				Q.push(to[i]);
			}
	}
	return false;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	memset(head, -1, sizeof head);
	cin >> n >> m;
	int u, v, ll, rr;
	for (int i = 0; i < m; i++) {
		cin >> u >> v >> ll >> rr;
		addBiEdge(u, v, ll, rr);
		bounds[i * 2] = ll, bounds[i * 2 + 1] = rr;
	}
	sort(bounds, bounds + 2 * m);
	for (int s = 0, e = 0; e < 2 * m; e++) {
		if (e < s)
			e = s;
		if (!BFS(bounds[s], bounds[e]))
			s++, e--;
		else
			ans = max(ans, bounds[e] - bounds[s] + 1);
	}
	if (!ans)
		cout << "Nice work, Dima!" << endl;
	else
		cout << ans << endl;
	return 0;
}
