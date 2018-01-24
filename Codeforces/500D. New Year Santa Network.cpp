/*
 * 500D. New Year Santa Network.cpp
 *
 *  Created on: Jan 24, 2018
 *      Author: Osama Hatem
 */
 
/*
http://codeforces.com/blog/entry/15488
*/

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1e5 + 5;

vector<int> adj[MAXN];
int n, a[MAXN], b[MAXN], c[MAXN], sz[MAXN];
double sum;

int dfs(int idx, int par) {
	for (int ch : adj[idx])
		if (ch != par)
			sz[idx] += dfs(ch, idx);
	return ++sz[idx];
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(6);

	cin >> n;
	for (int i = 1; i < n; i++) {
		cin >> a[i] >> b[i] >> c[i];
		adj[a[i]].push_back(b[i]);
		adj[b[i]].push_back(a[i]);
	}
	dfs(1, 0);

	for (int i = 1; i < n; i++) {
		int x = min(sz[a[i]], sz[b[i]]);
		sum += 1.0 * c[i] * x * (n - x);
	}

	int q, id, x, v;
	cin >> q;
	while (q--) {
		cin >> id >> v;
		x = min(sz[a[id]], sz[b[id]]);
		sum -= 1.0 * (c[id] - v) * x * (n - x);
		cout << sum * 6.0 / (1.0 * n * (n - 1)) << endl;
		c[id] = v;
	}
	return 0;
}
