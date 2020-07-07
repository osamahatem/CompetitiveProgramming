/*
 * 486D. Valid Sets.cpp
 *
 *  Created on: Jun 25, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 2e3 + 5;
const int MAXE = 2 * MAXN;
const int MOD = 1000000007;

int head[MAXN], nxt[MAXE], to[MAXE], last;
int n, d, val[MAXN];
bool vis[MAXN][MAXN];

void addEdge(int f, int t) {
	to[last] = t;
	nxt[last] = head[f];
	head[f] = last++;
}

void addBiEdge(int f, int t) {
	addEdge(f, t);
	addEdge(t, f);
}

long long dfs(int cur, int par, int &src) {
	vis[src][cur] = vis[cur][src] = 1;
	long long ret = 1;
	for (int i = head[cur]; i != -1; i = nxt[i]) {
		if (!vis[src][to[i]] && val[to[i]] >= val[src]
				&& val[to[i]] <= val[src] + d)
			ret = ret * (dfs(to[i], cur, src) + 1) % MOD;
	}
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	memset(head, -1, sizeof head);
	int u, v;
	cin >> d >> n;
	for (int i = 1; i <= n; i++)
		cin >> val[i];
	for (int i = 1; i < n; i++) {
		cin >> u >> v;
		addBiEdge(u, v);
	}
	long long ans = 0;
	for (int i = 1; i <= n; i++)
		ans = (ans + dfs(i, -1, i)) % MOD;
	cout << ans << endl;
	return 0;
}
