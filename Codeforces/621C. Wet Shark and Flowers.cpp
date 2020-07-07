/*
 * 621C. Wet Shark and Flowers.cpp
 *
 *  Created on: Mar 6, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1e5 + 5;
const double MONEY = 2000.0;

int l[MAXN], r[MAXN], divCnt[MAXN];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n, p;
	scanf("%d%d", &n, &p);
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &l[i], &r[i]);
		divCnt[i] = (r[i] - l[i] + 1) / p;
		int mod = (r[i] - l[i] + 1) % p;
		if (((p - (l[i] % p)) % p) < mod)
			divCnt[i]++;
	}
	l[n] = l[0], r[n] = r[0], divCnt[n] = divCnt[0];
	double ans = 0.0;
	for (int i = 0; i < n; i++) {
		int t1 = r[i] - l[i] + 1;
		int t2 = r[i + 1] - l[i + 1] + 1;
		long long valid = 1ll * divCnt[i] * t2
				+ 1ll * divCnt[i + 1] * (t1 - divCnt[i]);
		ans += MONEY * valid / (1ll * t1 * t2);
	}
	printf("%.6f\n", ans);
	return 0;
}
