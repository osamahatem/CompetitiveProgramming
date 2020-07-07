/*
 * 847K. Travel Cards.cpp
 *
 *  Created on: Sep 27, 2017
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

char from[25], to[25];
map<string, int> rnk;
int r;
map<pair<int, int>, int> cost;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n, a, b, k, f;
	scanf("%d%d%d%d%d", &n, &a, &b, &k, &f);
	int last = -1, total = 0;
	while (n--) {
		scanf("%s%s", from, to);
		if (!rnk.count(from))
			rnk[from] = ++r;
		if (!rnk.count(to))
			rnk[to] = ++r;
		int f = rnk[from], t = rnk[to];
		pair<int, int> bus = make_pair(f, t);
		if (bus.first > bus.second)
			swap(bus.first, bus.second);
		if (f == last)
			total += b, cost[bus] += b;
		else
			total += a, cost[bus] += a;
		last = t;
	}
	vector<int> all;
	for (auto it : cost)
		all.push_back(it.second);
	sort(all.rbegin(), all.rend());
	for (int i = 0; i < (int) all.size() && k; i++)
		if (all[i] > f)
			total += f - all[i], k--;
	printf("%d\n", total);
	return 0;
}
