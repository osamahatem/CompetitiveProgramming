/*
 * 424C. Magic Formulas.cpp
 *
 *  Created on: Jun 2, 2017
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1e6 + 5;

int xors[MAXN];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n, p, q = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &p);
		q ^= p;
	}
	for (int i = 1; i < n; i++)
		xors[i] = xors[i - 1] ^ i;
	for (int i = 1; i <= n; i++) {
		int temp = (n / i) & 1;
		if (temp)
			q ^= xors[i - 1];
		temp = n % i;
		q ^= xors[temp];
	}
	printf("%d\n", q);
	return 0;
}
