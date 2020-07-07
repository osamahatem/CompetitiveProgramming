/*
 * H. Hunter’s Apprentice.cpp
 *
 *  Created on: Oct 5, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int n, x[21], y[21];

int cross(int x1, int y1, int x2, int y2) {
	return x1 * y2 - y1 * x2;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%d%d", &x[i], &y[i]);
		x[n] = x[0], y[n] = y[0];
		int ans = 0;
		for (int i = 0; i < n; i++)
			ans += cross(x[i], y[i], x[i + 1], y[i + 1]);
		printf("%s\n", ans < 0 ? "run" : "fight");
	}
	return 0;
}
