/*
 * 533B. Work Group.cpp
 *
 *  Created on: Apr 15, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 2e5 + 5;

vector<int> adj[MAXN];
int eff[MAXN];
long long ans;

int solve(int n) {
	int mini = 1 << 30;
	for (int i = 0; i < (int) adj[n].size(); i++)
		mini = min(mini, solve(adj[n][i]));
	if ((int) adj[n].size() % 2 && mini > eff[n]) {
		ans -= eff[n];
		return mini;
	}
	if ((int) adj[n].size() % 2)
		ans -= mini;
	return eff[n];
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int p;
		scanf("%d%d", &p, &eff[i]);
		ans += eff[i];
		if (p != -1)
			adj[p].push_back(i);
	}
	solve(1);
	printf("%lld\n", ans);
	return 0;
}
