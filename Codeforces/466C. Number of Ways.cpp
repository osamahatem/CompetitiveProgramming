/*
 * 466C. Number of Ways.cpp
 *
 *  Created on: Jun 21, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 5e5 + 5;

int arr[MAXN];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//  freopen("out.out", "w", stdout);
#endif

	int n;
	long long sum = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		sum += arr[i];
	}
	if (sum % 3) {
		printf("0\n");
		return 0;
	}
	long long third = sum / 3, ans = 0;
	int cnt = 0;
	sum = 0;
	for (int i = 0; i + 1 < n; i++) {
		sum += arr[i];
		if (i && sum == third * 2)
			ans += cnt;
		if (sum == third)
			cnt++;
	}
	printf("%I64d\n", ans);
	return 0;
}
