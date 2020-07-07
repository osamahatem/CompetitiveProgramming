/*
 * 604B. More Cowbell.cpp
 *
 *  Created on: Feb 26, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1e5 + 5;

int n, k, sz[MAXN];

bool check(int box) {
	int kk = k, s = 0, e = n - 1;
	while (kk && s <= e) {
		if (sz[s] + sz[e] <= box)
			s++, e--;
		else
			e--;
		kk--;
	}
	return s > e;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++)
		scanf("%d", &sz[i]);
	int s = sz[n - 1], e = sz[n - 1] * 2;
	while (s < e) {
		int mid = (s + e) / 2;
		if (check(mid))
			e = mid;
		else
			s = mid + 1;
	}
	printf("%d\n", s);
	return 0;
}
