/*
 * I. Intergalactic Federation.cpp
 *
 *  Created on: Nov 5, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int x[1000], y[1000], n, d;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	freopen("intergalactic.in", "r", stdin);
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &d);
		for (int i = 0; i < n; i++)
			scanf("%d%d", &x[i], &y[i]);
		int maxi = -1, id = -1;
		for (int i = 0; i < n; i++) {
			int cnt = 0;
			for (int j = 0; j < n; j++) {
				if (i == j)
					continue;
				int dist = abs(x[i] - x[j]) + abs(y[i] - y[j]);
				if (dist <= d)
					cnt++;
			}
			if (cnt > maxi)
				maxi = cnt, id = i + 1;
		}
		printf("%d\n", id);
	}
	return 0;
}
