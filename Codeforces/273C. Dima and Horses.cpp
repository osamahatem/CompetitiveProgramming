/*
 * 273C. Dima and Horses.cpp
 *
 *  Created on: Jan 28, 2018
 *      Author: Osama Hatem
 */
 
/*
http://codeforces.com/blog/entry/6625

We use DFS to colour nodes. For each node, we colour its unvisited neighbours
with the opposite colour. Afterwards, we check if the node's colour is invalid
and switch it if necessary. There is always an answer.
*/

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 3e5 + 5;

bool col[MAXN], vis[MAXN];
vector<int> adj[MAXN];
int n, m;

void solve(int idx, bool c) {
	vis[idx] = 1, col[idx] = c;
	int x = 0;
	for (auto ch : adj[idx]) {
		if (!vis[ch])
			solve(ch, !c);
		x += col[ch] == col[idx];
	}
	if (x > 1)
		col[idx] = !col[idx];
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> n >> m;
	while (m--) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	for (int i = 1; i <= n; i++)
		if (!vis[i])
			solve(i, 0);

	for (int i = 1; i <= n; i++)
		cout << col[i];
	cout << endl;
	return 0;
}
