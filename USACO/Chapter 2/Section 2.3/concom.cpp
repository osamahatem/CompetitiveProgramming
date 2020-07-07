/*
 ID: 19semse1
 PROG: concom
 LANG: C++
 */
/*
 * concom.cpp
 *
 *  Created on: Mar 11, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int per[105], adj[105][105];
bool comp[105], vis[105];
set<int> cont;

void solve(int n) {
	queue<int> Q;
	Q.push(n);
	memset(vis, 0, sizeof vis);
	while (Q.size()) {
		int cur = Q.front();
		Q.pop();
		if (vis[cur])
			continue;
		vis[cur] = 1;
		for (int i = 1; i <= 100; i++)
			if (!vis[i] && adj[cur][i]) {
				per[i] += adj[cur][i];
				if (per[i] > 50)
					Q.push(i), cont.insert(i);
			}
	}
}

int main() {
//#ifndef ONLINE_JUDGE
	freopen("concom.in", "r", stdin);
	freopen("concom.out", "w", stdout);
//#endif

	int n, u, v, p;
	cin >> n;
	while (n--) {
		cin >> u >> v >> p;
		comp[u] = comp[v] = 1;
		adj[u][v] = p;
	}
	for (int i = 1; i <= 100; i++) {
		if (!comp[i])
			continue;
		memset(per, 0, sizeof per);
		per[i] = 100;
		cont.clear();
		solve(i);
		for (set<int>::iterator it = cont.begin(); it != cont.end(); it++)
			cout << i << " " << *it << endl;
	}
	return 0;
}
