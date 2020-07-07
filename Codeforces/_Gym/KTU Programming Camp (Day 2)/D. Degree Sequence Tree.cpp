/*
 * D. Degree Sequence Tree.cpp
 *
 *  Created on: May 13, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int deg[200005], a[200005], b[200005];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n, sum = 0, cnt = 0, idx = 0;
	queue<int> active;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &deg[i]);
		sum += deg[i];
		if (deg[i] < 1 || deg[i] >= n) {
			printf("-1\n");
			return 0;
		}
		if (deg[i] == 1)
			active.push(i), cnt++;
	}
	if (sum != 2 * n - 2) {
		printf("-1\n");
		return 0;
	}
	for (int i = 0; i < n; i++) {
		if (deg[i] == 1)
			continue;
		cnt++;
		int req = deg[i] - 1;
		if (cnt == n)
			req++;
		if ((int) active.size() < req) {
			printf("-1\n");
			return 0;
		}
		while (req--) {
			a[idx] = i;
			b[idx++] = active.front();
			active.pop();
		}
		active.push(i);
	}
	for (int i = 0; i < n - 1; i++)
		printf("%d %d\n", ++a[i], ++b[i]);
	return 0;
}
