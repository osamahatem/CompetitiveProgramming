/*
 * B. Balloon Warehouse.cpp
 *
 *  Created on: Oct 14, 2017
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 2e5 + 5;

int n, l, r;
vector<pair<int, int>> state[MAXN], in;
long long sz[MAXN];
vector<int> ans;

void solve(int idx, int cnt) {
	ans.push_back(idx), cnt--;
	for (int i = 0; i < (int) state[idx].size() && cnt > 0; i++) {
		solve(state[idx][i].first, state[idx][i].second);
		cnt -= state[idx][i].second;
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	scanf("%d%d%d", &n, &l, &r);
	in.resize(n);
	for (int i = 0; i < n; i++)
		scanf("%d%d", &in[i].first, &in[i].second);
	reverse(in.begin(), in.end());
	for (int i = 0; i < MAXN; i++)
		sz[i]++;
	for (int i = 0; i < n; i++) {
		int x = in[i].first, y = in[i].second;
		state[x].push_back(make_pair(y, sz[y]));
		sz[x] += sz[y];
	}
	solve(0, r);
	for (int i = l; i < r; i++) {
		if (i > l)
			printf(" ");
		printf("%d", ans[i % (int) ans.size()]);
	}
	printf("\n");
	return 0;
}
