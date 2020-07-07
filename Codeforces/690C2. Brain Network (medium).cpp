/*
 * 690C2. Brain Network (medium).cpp
 *
 *  Created on: Jul 10, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 100005;

vector<int> adj[MAXN];
int ans = 0;

int solve(int n, int p) {
	multiset<int> ch;
	for (int i = 0; i < (int) adj[n].size(); i++)
		if (adj[n][i] != p) {
			int d = 1 + solve(adj[n][i], n);
			ch.insert(d);
			if (ch.size() > 2)
				ch.erase(ch.begin());
		}
	if (ch.empty())
		return 0;
	int ret = *ch.rbegin();
	int temp = 0;
	while (ch.size()) {
		temp += *ch.begin();
		ch.erase(ch.begin());
	}
	ans = max(ans, temp);
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n, m, a, b;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d%d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	solve(1, -1);
	printf("%d\n", ans);
	return 0;
}
