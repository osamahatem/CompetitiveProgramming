/*
 * 617C. Watering Flowers.cpp
 *
 *  Created on: Feb 19, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int Px, Py;

long long distSq(int x1, int y1, int x2, int y2) {
	int dx = x1 - x2, dy = y1 - y2;
	return 1ll * dx * dx + 1ll * dy * dy;
}

bool cmp(pair<int, int> p1, pair<int, int> p2) {
	return distSq(p1.first, p1.second, Px, Py)
			< distSq(p2.first, p2.second, Px, Py);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n, x1, y1, x2, y2;
	scanf("%d%d%d%d%d", &n, &x1, &y1, &x2, &y2);
	vector<pair<int, int>> all(n);
	for (int i = 0; i < n; i++)
		scanf("%d%d", &all[i].first, &all[i].second);
	Px = x1, Py = y1;
	sort(all.begin(), all.end(), cmp);
	long long ans = distSq(all[n - 1].first, all[n - 1].second, x1, y1);
	long long ext = 0;
	for (int i = n - 1; i > 0; i--) {
		ext = max(ext, distSq(all[i].first, all[i].second, x2, y2));
		ans = min(ans,
				distSq(all[i - 1].first, all[i - 1].second, x1, y1) + ext);
	}
	ext = max(ext, distSq(all[0].first, all[0].second, x2, y2));
	ans = min(ans, ext);
	printf("%lld\n", ans);
	return 0;
}
