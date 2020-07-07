/*
 * 2011. Long Statement.cpp
 *
 *  Created on: Aug 2, 2014
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	double ans = 1;
	int n, x, cnt[4];
	memset(cnt, 0, sizeof cnt);
	scanf("%d", &n);
	for (int i = 2; i <= n; i++)
		ans *= i;
	while (n--) {
		scanf("%d", &x);
		cnt[x]++;
	}
	for (int c = 1; c <= 3; c++)
		for (int i = 2; i <= cnt[c]; i++)
			ans /= i;
	ans += 1e-9;

	if (ans < 6.0)
		printf("No\n");
	else
		printf("Yes\n");
	return 0;
}
