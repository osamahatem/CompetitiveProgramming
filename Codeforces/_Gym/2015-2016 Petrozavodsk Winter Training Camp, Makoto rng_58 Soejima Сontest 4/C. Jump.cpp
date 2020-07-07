/*
 * C. Jump.cpp
 *
 *  Created on: May 1, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int SHIFT = 20001;

int n, q, pivot[205], dist[50005][2];

void BFS(int src) {
	memset(dist, -1, sizeof dist);
	queue<int> Q;
	Q.push(src), dist[src + SHIFT][0] = 0;
	int steps = 0;
	while (Q.size()) {
		steps++;
		int sz = Q.size();
		while (sz--) {
			int cur = Q.front();
			Q.pop();
			for (int i = 0; i < n; i++) {
				int np = 2 * pivot[i] - cur;
				if (np < SHIFT + SHIFT / 2 && np > -SHIFT
						&& dist[np + SHIFT][steps % 2] == -1)
					Q.push(np), dist[np + SHIFT][steps % 2] = steps;
			}
		}
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &pivot[i]);
	BFS(0);
	scanf("%d", &q);
	while (q--) {
		int s, t;
		scanf("%d%d", &s, &t);
		int ans = 1 << 30;
		if (dist[s + t + SHIFT][1] != -1)
			ans = dist[s + t + SHIFT][1];
		if (dist[t - s + SHIFT][0] != -1)
			ans = min(ans, dist[t - s + SHIFT][0]);
		ans = (ans == 1 << 30 ? -1 : ans);
		printf("%d\n", ans);
	}
	return 0;
}
