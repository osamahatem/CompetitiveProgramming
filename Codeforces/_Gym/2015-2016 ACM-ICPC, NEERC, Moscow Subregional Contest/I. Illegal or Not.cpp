/*
 * I. Illegal or Not.cpp
 *
 *  Created on: Sep 27, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1826;
const int LIM = 90;

int n, sum[MAXN + 2];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n;
	scanf("%d", &n);
	while (n--) {
		int a, b;
		scanf("%d%d", &a, &b);
		for (int i = a; i <= b; i++)
			sum[i]++;
	}
	bool ans = true;
	for (int i = 1; i <= MAXN; i++) {
		sum[i] += sum[i - 1];
		if (i >= 180 && sum[i] - sum[i - 180] > LIM)
			ans = false;
	}
	printf("%s\n", ans ? "Yes" : "No");
	return 0;
}
