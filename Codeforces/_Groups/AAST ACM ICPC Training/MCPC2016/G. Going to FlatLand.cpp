/*
 * G. Going to FlatLand.cpp
 *
 *  Created on: Nov 5, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1e5 + 5;
const double EPS = 1e-4;

int n, k, arr[MAXN];

bool check(double r) {
	double e = 2.0 * r + arr[0];
	int idx = 0;
	for (int i = 0; i < k; i++) {
		while (idx < n && arr[idx] - e < EPS)
			idx++;
		if (idx == n)
			return true;
		e = 2.0 * r + arr[idx];
	}
	return false;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	freopen("going.in", "r", stdin);
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &k);
		for (int i = 0; i < n; i++)
			scanf("%d", &arr[i]);
		sort(arr, arr + n);
		double s = 0.0, e = 1e9 + 5;
		for (double sz = (e - s) / 2.0; sz > EPS; sz *= 0.5) {
			if (!check(s + sz))
				s += sz;
		}
		printf("%.3f\n", s);
	}
	return 0;
}
