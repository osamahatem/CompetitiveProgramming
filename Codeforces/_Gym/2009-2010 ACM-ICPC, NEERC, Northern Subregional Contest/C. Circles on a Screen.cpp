/*
 * C. Circles on a Screen.cpp
 *
 *  Created on: Oct 7, 2017
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const double EPS = 1e-9;

int ev[20005], x[105], y[105], r[105];
int w, h, n;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	freopen("circles.in", "r", stdin);
	freopen("circles.out", "w", stdout);

	scanf("%d%d%d", &w, &h, &n);
	for (int i = 0; i < n; i++)
		scanf("%d%d%d", &x[i], &y[i], &r[i]);
	int ans = 0;
	for (int i = 0; i < w; i++) {
		memset(ev, 0, sizeof ev);
		for (int j = 0; j < n; j++) {
			int diff = r[j] * r[j] - (x[j] - i) * (x[j] - i);
			if (diff < 0)
				continue;
			int lim = (int) (sqrt(diff) + EPS);
			ev[max(y[j] - lim, 0)]++, ev[min(y[j] + lim + 1, h)]--;
		}
		int cur = 0;
		for (int j = 0; j < h; j++) {
			cur += ev[j];
			if (!cur)
				ans++;
		}
	}
	printf("%d\n", ans);
	return 0;
}
