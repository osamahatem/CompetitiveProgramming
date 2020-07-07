/*
 * 1998. The old Padawan.cpp
 *
 *  Created on: Aug 4, 2014
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

	int n, m, k, x, sum[100005], back[100005];
	sum[0] = 0;
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &x);
		sum[i] = x + sum[i - 1];
		back[i] = (int) (lower_bound(sum, sum + i, sum[i - 1] - k) - sum) - 1;
		if (back[i] < 0)
			back[i] = 0;
	}
	int cur = 0;
	long long t = 0;
	while (m--) {
		scanf("%d", &x);
		if (t + n - cur < x)
			break;
		cur = back[cur + x - t];
		t += x - t;
	}
	printf("%lld\n", t + n - cur);
	return 0;
}
