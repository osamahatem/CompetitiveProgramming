/*
 * 598C. Nearest vectors.cpp
 *
 *  Created on: Nov 13, 2015
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

	int n, x, y;
	scanf("%d", &n);
	vector<pair<double, int>> all(n);
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &x, &y);
		all[i] = make_pair(atan2(y, x), i);
	}
	sort(all.begin(), all.end());
	double ans = 2.0 * acos(-1.0);
	int a = 0, b = 0;
	for (int i = 1; i < n; i++)
		if (all[i].first - all[i - 1].first < ans)
			ans = all[i].first - all[i - 1].first, a = all[i - 1].second + 1, b =
					all[i].second + 1;
	if (2 * acos(-1.0) - (all[n - 1].first - all[0].first) < ans)
		ans = 2 * acos(-1.0) - (all[n - 1].first - all[0].first), a =
				all[0].second + 1, b = all[n - 1].second + 1;
	printf("%d %d\n", a, b);
	return 0;
}
