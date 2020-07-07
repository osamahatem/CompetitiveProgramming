/*
 * 724C. Ray Tracing.cpp
 *
 *  Created on: Feb 8, 2017
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1e5 + 5;

int n, m, k;
pair<int, int> sensors[MAXN];
long long ans[MAXN];
map<int, vector<int>> d1, d2;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	memset(ans, -1, sizeof ans);
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < k; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		sensors[i].first = x, sensors[i].second = y;
		d1[x - y].push_back(i), d2[x + y].push_back(i);
	}
	int x = 0, y = 0, dx = 1, dy = 1;
	long long t = 0;
	while (1) {
		if (dx == dy) {
			int diag = x - y;
			for (int i = 0; i < (int) d1[diag].size(); i++) {
				int idx = d1[diag][i];
				if (ans[idx] == -1)
					ans[idx] = t + abs(x - sensors[idx].first);
			}
		} else {
			int diag = x + y;
			for (int i = 0; i < (int) d2[diag].size(); i++) {
				int idx = d2[diag][i];
				if (ans[idx] == -1)
					ans[idx] = t + abs(x - sensors[idx].first);
			}
		}
		int distX = (dx == 1 ? n - x : x);
		int distY = (dy == 1 ? m - y : y);
		if (distX == distY)
			break;
		x += dx * min(distX, distY), y += dy * min(distX, distY);
		t += min(distX, distY);
		if (distX < distY)
			dx *= -1;
		else
			dy *= -1;
	}
	for (int i = 0; i < k; i++)
		printf("%lld\n", ans[i]);
	return 0;
}
