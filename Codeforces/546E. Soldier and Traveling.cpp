/*
 * 546E. Soldier and Traveling.cpp
 *
 *  Created on: May 22, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 210;
const int MAXE = 1510;
const int SRC = MAXN - 1;
const int SNK = MAXN - 2;
const int INF = 5000;

int head[MAXN], to[MAXE], nxt[MAXE], cap[MAXE], last = 0;
int out[105][105];
bool vis[MAXN];

void addEdge(int f, int t, int c) {
	to[last] = t;
	cap[last] = c;
	nxt[last] = head[f];
	head[f] = last++;
}

void addAugEdge(int f, int t, int c) {
	addEdge(f, t, c);
	addEdge(t, f, 0);
}

bool DFS(int n) {
	if (n == SNK)
		return true;
	vis[n] = 1;
	for (int i = head[n]; i != -1; i = nxt[i]) {
		if (cap[i] && !vis[to[i]] && DFS(to[i])) {
			cap[i]--, cap[i ^ 1]++;
			return true;
		}
	}
	return false;
}

int maxFlow() {
	int ans = 0;
	while (DFS(SRC)) {
		memset(vis, 0, sizeof vis);
		ans++;
	}
	return ans;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	memset(head, -1, sizeof head);
	int n, m, st[105], tar[105], a, b, sums = 0, sume = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> st[i], sums += st[i];
	for (int i = 0; i < n; i++)
		cin >> tar[i], sume += tar[i];
	for (int i = 0; i < n; i++) {
		addAugEdge(SRC, i, st[i]);
		addAugEdge(n + i, SNK, tar[i]);
	}
	while (m--) {
		cin >> a >> b;
		a--, b--;
		addAugEdge(a, n + b, INF);
		addAugEdge(b, n + a, INF);
	}
	for (int i = 0; i < n; i++)
		addAugEdge(i, n + i, INF);
	int mf = maxFlow();
	if (mf != sume || sums != sume) {
		cout << "NO" << endl;
		return 0;
	}
	for (int i = 0; i < n; i++) {
		for (int e = head[i]; e != -1; e = nxt[e]) {
			if (to[e] != SRC) {
				int tc = cap[e] + cap[e ^ 1];
				int f = tc - cap[e], t = to[e] - n;
				out[i][t] = f;
			}
		}
	}
	cout << "YES" << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (j)
				cout << " ";
			cout << out[i][j];
		}
		cout << endl;
	}
	return 0;
}
