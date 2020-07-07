/*
 * 260C. Balls and Boxes.cpp
 *
 *  Created on: May 8, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

long long all[100005];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n, x, mini = 1e9 + 5;
	scanf("%d%d", &n, &x);
	x--;
	for (int i = 0; i < n; i++) {
		scanf("%lld", &all[i]);
		if (all[i] < mini)
			mini = all[i];
	}
	long long sum = 1ll * n * mini;
	for (int i = 0; i < n; i++)
		all[i] -= mini;
	int idx = x;
	while (all[idx]) {
		sum++;
		all[idx]--;
		idx = (idx - 1 + n) % n;
	}
	all[idx] += sum;
	for (int i = 0; i < n; i++) {
		if (i)
			printf(" ");
		printf("%lld", all[i]);
	}
	printf("\n");
	return 0;
}
