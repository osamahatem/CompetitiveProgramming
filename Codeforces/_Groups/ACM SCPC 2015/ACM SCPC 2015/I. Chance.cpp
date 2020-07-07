/*
 * I. Chance.cpp
 *
 *  Created on: Sep 29, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1e5 + 5;

int ans[MAXN];

bool isPrime(int x) {
	for (int i = 2; i * i <= x; i++)
		if (x % i == 0)
			return false;
	return x != 1;
}

int countOnes(int x) {
	int ret = 0;
	while (x) {
		ret += x & 1;
		x /= 2;
	}
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	freopen("chance.in", "r", stdin);
	for (int i = 1; i < MAXN; i++)
		ans[i] = ans[i - 1] + isPrime(countOnes(i));
	int T, l, r;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &l, &r);
		printf("%d\n", ans[r] - (l ? ans[l - 1] : 0));
	}
	return 0;
}
