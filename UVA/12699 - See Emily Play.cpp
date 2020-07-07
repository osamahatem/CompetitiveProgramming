/*
 * 12699 - See Emily Play.cpp
 *
 *  Created on: Aug 9, 2014
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

double d[1000005], s[1000005], a[1000005];
bool vis[1000005];

void solve(int n) {
	if (n < 2)
		return;
	if (vis[n])
		return;
	vis[n] = 1;
	if (n % 2 == 0) {
		solve(n / 2);
		d[n] = 1 + d[n / 2];
		s[n] = s[n / 2];
		a[n] = a[n / 2];
		return;
	}
	solve(n + 1);
	solve(n - 1);
	a[n] = (1 + a[n + 1] + a[n - 1]) / 2.0;
	s[n] = (1 + s[n + 1] + s[n - 1]) / 2.0;
	d[n] = (d[n - 1] + d[n + 1]) / 2.0;
	return;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int t;
	d[0] = s[0] = a[0] = 0.0;
	d[1] = s[1] = a[1] = 1.0;
	scanf("%d", &t);
	while (t--) {
		int n, cd, cs, ca;
		scanf("%d%d%d%d", &n, &cd, &cs, &ca);
		solve(n);
		printf("%.3f\n", cd * d[n] + cs * s[n] + ca * a[n]);
	}
	return 0;
}
