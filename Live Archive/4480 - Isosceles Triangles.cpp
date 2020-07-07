/*
 * 4480 - Isosceles Triangles.cpp
 *
 *  Created on: Sep 21, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

typedef long long ll;

int x[1005], y[1005];

ll DIST(int x1, int y1, int x2, int y2) {
	ll X = x1 - x2, Y = y1 - y2;
	return X * X + Y * Y;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int N;
	while (scanf("%d", &N), N) {
		int ans = 0;
		for (int i = 0; i < N; i++) {
			scanf("%d%d", &x[i], &y[i]);
		}
		for (int i = 0; i < N; i++) {
			vector<ll> distance;
			for (int j = 0; j < N; j++)
				distance.push_back(DIST(x[i], y[i], x[j], y[j]));
			sort(distance.begin(), distance.end());
			int cnt = 1;
			for (int j = 1; j < (int) distance.size(); j++) {
				if (distance[j] == distance[j - 1])
					ans += cnt++;
				else
					cnt = 1;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
