/*
 * 907 - Winterim Backpacking Trip.cpp
 *
 *  Created on: Sep 18, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int n, k, arr[601];

bool check(int dist) {
	int idx = 0, kk = k, d = dist;
	while (idx <= n && kk) {
		if (d >= arr[idx])
			d -= arr[idx++];
		else
			kk--, d = dist;
	}
	return idx > n;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	while (scanf("%d%d", &n, &k) != EOF) {
		k++;
		for (int i = 0; i <= n; i++)
			scanf("%d", &arr[i]);
		int s = 1, e = 1 << 30;
		while (s < e) {
			int m = (s + e) / 2;
			if (check(m))
				e = m;
			else
				s = m + 1;
		}
		printf("%d\n", s);
	}
	return 0;
}
