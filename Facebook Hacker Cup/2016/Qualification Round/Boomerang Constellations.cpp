/*
 * Boomerang Constellations.cpp
 *
 *  Created on: Jan 9, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

long long distSq(int x1, int y1, int x2, int y2) {
	long long dx = x2 - x1, dy = y2 - y1;
	return dx * dx + dy * dy;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
	freopen("out.out", "w", stdout);
#endif

	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		int N;
		scanf("%d", &N);
		vector<pair<int, int>> all(N);
		for (int i = 0; i < N; i++)
			scanf("%d%d", &all[i].first, &all[i].second);
		long long ans = 0;
		for (int i = 0; i < N; i++) {
			vector<long long> dist;
			for (int j = 0; j < N; j++)
				if (i != j)
					dist.push_back(
							distSq(all[i].first, all[i].second, all[j].first,
									all[j].second));
			sort(dist.begin(), dist.end());
			int cnt = 1;
			for (int j = 1; j < (int) dist.size(); j++)
				if (dist[j] != dist[j - 1])
					cnt = 1;
				else
					ans += cnt++;
		}
		printf("Case #%d: %lld\n", t, ans);
	}
	return 0;
}
