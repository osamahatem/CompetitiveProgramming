/*
 * 367C. Sereja and the Arrangement of Numbers.cpp
 *
 *  Created on: Jul 23, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int arr[100001];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++)
		scanf("%*d%d", &arr[i]);
	sort(arr + 1, arr + 1 + m, greater<int>());
	long long ans = 0, len = 0, i;
	for (i = 1; len <= n && i <= m; i++) {
		ans += arr[i];
		len = 1ll * i * (i - 1) / 2 + 1;
		if (i % 2 == 0)
			len += i / 2 - 1;
	}
	if (len > n)
		ans -= arr[--i];
	printf("%lld\n", ans);
	return 0;
}
