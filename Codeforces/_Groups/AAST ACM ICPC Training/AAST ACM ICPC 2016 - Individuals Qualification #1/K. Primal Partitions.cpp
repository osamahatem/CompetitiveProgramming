/*
 * K. Primal Partitions.cpp
 *
 *  Created on: Aug 29, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXV = 1e6 + 5;

int n, k, factor[MAXV], arr[20000];

void init() {
	for (int i = 2; i < MAXV; i++)
		if (!factor[i])
			for (int j = i; j < MAXV; j += i)
				factor[j] = i;
}

bool check(int p) {
	int i, kk;
	for (i = 0, kk = k; i < n && kk; i++, kk--) {
		int idx = i + 1, g = arr[i];
		if (factor[g] < p)
			return false;
		while (idx < n && factor[__gcd(g, arr[idx])] >= p) {
			g = __gcd(g, arr[idx]);
			idx++;
		}
		i = idx - 1;
	}
	return i == n;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	init();
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	int s = 0, e = MAXV;
	while (s < e) {
		int m = (s + e + 1) / 2;
		if (check(m))
			s = m;
		else
			e = m - 1;
	}
	printf("%d\n", s);
	return 0;
}
