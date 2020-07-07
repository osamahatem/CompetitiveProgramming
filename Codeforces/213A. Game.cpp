/*
 * 213A. Game.cpp
 *
 *  Created on: Aug 24, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int n, deg[205], pc[205], out[205], adj[205][205], tdeg[205];

int solve(int spc) {
	memcpy(tdeg, deg, sizeof deg);
	int left = n, tt = 0;
	queue<int> Q[3];
	for (int i = 1; i <= n; i++)
		if (!deg[i])
			Q[pc[i]].push(i);
	while (left) {
		if (Q[spc].empty()) {
			spc = (spc + 1) % 3;
			tt++;
			continue;
		}
		left--, tt++;
		int cur = Q[spc].front();
		Q[spc].pop();
		for (int i = 0; i < out[cur]; i++) {
			tdeg[adj[cur][i]]--;
			if (!tdeg[adj[cur][i]])
				Q[pc[adj[cur][i]]].push(adj[cur][i]);
		}
	}
	return tt;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int x;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> pc[i];
		pc[i]--;
	}
	for (int i = 1; i <= n; i++) {
		cin >> deg[i];
		for (int j = 0; j < deg[i]; j++) {
			cin >> x;
			adj[x][out[x]++] = i;
		}
	}
	cout << min(solve(0), min(solve(1), solve(2))) << endl;
	return 0;
}
