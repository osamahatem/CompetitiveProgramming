/*
 * 894D. Ralph And His Tour in Binary Country.cpp
 *
 *  Created on: Nov 20, 2017
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1e6 + 6;

int n, q, cost[MAXN];
vector<int> lens[MAXN];
vector<long long> sums[MAXN];

void preCalc(int idx) {
	if (idx * 2 <= n)
		preCalc(idx * 2);
	if (idx * 2 + 1 <= n)
		preCalc(idx * 2 + 1);
	lens[idx].push_back(0);
	int i = 0, j = 0;
	int sza = idx * 2 <= n ? (int) lens[idx * 2].size() : 0;
	int szb = idx * 2 + 1 <= n ? (int) lens[idx * 2 + 1].size() : 0;
	while (i < sza && j < szb) {
		if (lens[idx * 2][i] + cost[idx * 2 - 1]
				< lens[idx * 2 + 1][j] + cost[idx * 2])
			lens[idx].push_back(lens[idx * 2][i++] + cost[idx * 2 - 1]);
		else
			lens[idx].push_back(lens[idx * 2 + 1][j++] + cost[idx * 2]);
	}
	while (i < sza)
		lens[idx].push_back(lens[idx * 2][i++] + cost[idx * 2 - 1]);
	while (j < szb)
		lens[idx].push_back(lens[idx * 2 + 1][j++] + cost[idx * 2]);
	sums[idx].resize(lens[idx].size());
	for (int i = 0; i < (int) lens[idx].size(); i++)
		sums[idx][i] = (i ? sums[idx][i - 1] : 0ll) + lens[idx][i];
}

long long solve(int node, long long h) {
	int idx = upper_bound(lens[node].begin(), lens[node].end(), h)
			- lens[node].begin() - 1;
	if (idx >= 0)
		return 1ll * (idx + 1) * h - sums[node][idx];
	return 0;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	scanf("%d%d", &n, &q);
	for (int i = 1; i < n; i++)
		scanf("%d", &cost[i]);
	preCalc(1);
	while (q--) {
		int a, h;
		scanf("%d%d", &a, &h);
		long long ans = solve(a, h);
		int last = a;
		int hh = cost[a - 1];
		a /= 2;
		while (a && h >= hh) {
			int ch = a * 4 + 1 - last;
			if (ch <= n)
				ans += solve(ch, h - hh - cost[ch - 1]);
			ans += h - hh;
			last = a;
			hh += cost[a - 1];
			a /= 2;
		}
		printf("%lld\n", ans);
	}
	return 0;
}
