/*
 * 2000. Grand Theft Array V.cpp
 *
 *  Created on: Aug 2, 2014
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
#endif

	int n, a, b, arr[100005], sum[100005], x;
	sum[0] = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
		sum[i] = sum[i - 1] + arr[i];
	}
	scanf("%d%d", &a, &b);
	int mid = (a + b) / 2;
	if (a == b)
		x = arr[a] + max(sum[a - 1], sum[n] - sum[a]);
	else if ((a - b) % 2)
		if (a > b)
			x = sum[n] - sum[mid];
		else
			x = sum[mid];
	else if (a > b)
		x = sum[n] - sum[mid - 1];
	else
		x = sum[mid];
	printf("%d %d\n", x, sum[n] - x);
	return 0;
}
