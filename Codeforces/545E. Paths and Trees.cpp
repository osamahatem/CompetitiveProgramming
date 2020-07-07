/*
 * 545E. Paths and Trees.cpp
 *
 *  Created on: May 19, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 3e5 + 5;
const int MAXE = 2 * MAXN;

struct node {
	int n, lw;
	long long tw;

	const bool operator <(const node &a) const {
		if (tw != a.tw)
			return tw > a.tw;
		return lw > a.lw;
	}
};

int src, head[MAXN], to[MAXE], w[MAXE], id[MAXE], nxt[MAXE], last;
bool used[MAXN];
long long dist[MAXN], totW = 0;

void addEdge(int f, int t, int ww, int idd) {
	to[last] = t;
	w[last] = ww;
	id[last] = idd;
	nxt[last] = head[f];
	head[f] = last++;
}

void addBiEdge(int f, int t, int ww, int idd) {
	addEdge(f, t, ww, idd);
	addEdge(t, f, ww, idd);
}

void Solve() {
	priority_queue<node> Q;
	dist[src] = 0;
	for (int i = head[src]; i != -1; i = nxt[i])
		Q.push(node { i, w[i], w[i] });
	while (Q.size()) {
		node cur = Q.top();
		Q.pop();
		int t = to[cur.n];
		if (cur.tw < dist[t]) {
			dist[t] = cur.tw;
			used[id[cur.n]] = 1;
			totW += cur.lw;
			for (int i = head[t]; i != -1; i = nxt[i])
				Q.push(node { i, w[i], cur.tw + w[i] });
		}
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	memset(head, -1, sizeof head);
	fill(dist, dist + MAXN, 1ll << 60);
	last = 0;
	int n, m, u, v, w;
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		cin >> u >> v >> w;
		addBiEdge(u, v, w, i);
	}
	cin >> src;
	Solve();
	vector<int> ans;
	for (int i = 1; i <= m; i++)
		if (used[i])
			ans.push_back(i);
	cout << totW << endl;
	for (int i = 0; i < (int) ans.size(); i++) {
		if (i)
			cout << " ";
		cout << ans[i];
	}
	if (totW)
		cout << endl;
	return 0;
}
