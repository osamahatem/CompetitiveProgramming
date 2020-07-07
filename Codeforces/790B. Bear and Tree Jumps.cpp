/*
 * 790B. Bear and Tree Jumps.cpp
 *
 *  Created on: Mar 21, 2017
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 2e5 + 5;

int n, k, subtree[MAXN];
vector<int> adj[MAXN];
long long ans;

vector<int> solve(int idx, int par) {
	subtree[idx]++;
	vector<int> ret(k, 0);
	for (int to : adj[idx]) {
		if (to == par)
			continue;
		vector<int> temp = solve(to, idx);
		subtree[idx] += subtree[to];
		ans += 1ll * subtree[to] * (n - subtree[to]);
		temp[0]++;
		for (int i = k - 1; i; i--)
			swap(temp[i], temp[i - 1]);
		for (int i = 0; i < k; i++) {
			ans += 1ll * ((k - i) % k) * temp[i];
			for (int j = 0; j < k; j++) {
				int func = (k - ((i + j) % k)) % k;
				ans += 1ll * ret[j] * temp[i] * func;
			}
		}
		for (int i = 0; i < k; i++)
			ret[i] += temp[i];
	}
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	scanf("%d%d", &n, &k);
	for (int i = 1; i < n; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		adj[a].push_back(b), adj[b].push_back(a);
	}
	solve(1, 0);
	cout << ans / k << endl;
	return 0;
}
