/*
 * 1929. Teddybears are not for Everyone.cpp
 *
 *  Created on: Aug 6, 2014
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n, m, x;
	bool flag = 0;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d", &x);
		if (x == 1)
			flag = 1;
	}
	int groups = n / 3 - 1;
	m -= flag;
	long long ans = 0;
	if (flag && m >= groups && n - m > 2)
		ans += (n - m - 1) * (n - m - 2) / 2;
	if (m - 1 >= groups && n - m > 1)
		ans += (n - 1 - m) * m;
	if (m - 2 >= groups)
		ans += m * (m - 1) / 2;
	printf("%lld\n", ans);
	return 0;
}
