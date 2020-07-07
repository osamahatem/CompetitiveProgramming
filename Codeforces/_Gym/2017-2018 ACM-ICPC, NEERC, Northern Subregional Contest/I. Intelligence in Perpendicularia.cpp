/*
 * I. Intelligence in Perpendicularia.cpp
 *
 *  Created on: Nov 11, 2017
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	freopen("intel.in", "r", stdin);
	freopen("intel.out", "w", stdout);
	int n;
	scanf("%d", &n);
	vector<pair<int, int>> all(n);
	map<int, int> xs, ys;
	for (int i = 0; i < n; i++)
		scanf("%d%d", &all[i].first, &all[i].second);
	for (int i = 0; i < n; i++) {
		int j = (i + 1) % n;
		xs[min(all[i].first, all[j].first)]++;
		xs[max(all[i].first, all[j].first)]--;
		ys[min(all[i].second, all[j].second)]++;
		ys[max(all[i].second, all[j].second)]--;
	}
	int last = -1e7, cur = 0, ans = 0;
	for (pair<int, int> p : xs) {
		ans += max(cur - 2, 0) * (p.first - last);
		cur += p.second;
		last = p.first;
	}
	last = 1e-7, cur = 0;
	for (pair<int, int> p : ys) {
		ans += max(cur - 2, 0) * (p.first - last);
		cur += p.second;
		last = p.first;
	}
	printf("%d\n", ans);
	return 0;
}
