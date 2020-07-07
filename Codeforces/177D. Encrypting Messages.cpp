/*
 * 177D. Encrypting Messages.cpp
 *
 *  Created on: Apr 14, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1e5 + 5;

int a[MAXN], b[MAXN];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n, m, c;
	scanf("%d%d%d", &n, &m, &c);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < m; i++) {
		scanf("%d", &b[i]);
		if (i)
			b[i] = (b[i] + b[i - 1]) % c;
	}
	int s = 0, e = -1;
	for (int i = 0; i < n; i++) {
		if (e + 1 < m)
			e++;
		if (n - i < m)
			s++;
		a[i] = (a[i] + b[e] - (s ? b[s - 1] : 0) + c) % c;
	}
	for (int i = 0; i < n; i++) {
		if (i)
			printf(" ");
		printf("%d", a[i]);
	}
	printf("\n");
	return 0;
}
