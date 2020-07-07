/*
 * 378B. Semifinals.cpp
 *
 *  Created on: Jun 22, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int n, a[100005], b[100005];
bool aa[100005], bb[100005];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &a[i], &b[i]);
		if ((i + 1) * 2 <= n)
			aa[i] = 1, bb[i] = 1;
	}
	int ia = 0, ib = 0;
	while (ia + ib < n) {
		if (ia < n && a[ia] < b[ib])
			aa[ia++] = 1;
		else
			bb[ib++] = 1;
	}
	for (int i = 0; i < n; i++)
		printf("%d", aa[i]);
	printf("\n");
	for (int i = 0; i < n; i++)
		printf("%d", bb[i]);
	printf("\n");
	return 0;
}
