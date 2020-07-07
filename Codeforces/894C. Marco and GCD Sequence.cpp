/*
 * 894C. Marco and GCD Sequence.cpp
 *
 *  Created on: Nov 20, 2017
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int m, S[1005];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	scanf("%d", &m);
	for (int i = 0; i < m; i++)
		scanf("%d", &S[i]);
	int g = S[0];
	for (int i = 1; i < m; i++)
		g = __gcd(g, S[i]);
	if (g != S[0]) {
		printf("-1\n");
		return 0;
	}
	printf("%d\n", 2 * m);
	for (int i = 0; i < m; i++) {
		if (i)
			printf(" ");
		printf("%d %d", S[i], g);
	}
	printf("\n");
	return 0;
}
