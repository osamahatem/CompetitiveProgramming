/*
 * 390C. Inna and Candy Boxes.cpp
 *
 *  Created on: Aug 15, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1e5 + 5;

int good[MAXN], bad[MAXN];
char candy[MAXN];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n, k, w, l, r;
	scanf("%d%d%d%s", &n, &k, &w, candy);
	for (int i = 0; i + 1 < k; i++) {
		good[i] = candy[i] == '1';
		for (int j = 0; j < i; j++)
			bad[i] += candy[j] == '1';
	}
	for (int i = k - 1; i < n; i++) {
		good[i] = candy[i] == '1';
		good[i] += good[i - k];
		bad[i] += bad[i - k];
		for (int kk = 1; kk < k; kk++)
			bad[i] += candy[i - kk] == '1';
	}
	while (w--) {
		scanf("%d%d", &l, &r);
		l--, r--;
		int len = r - l + 1;
		int gg = good[r] - (l ? good[l - 1] : 0);
		int bb = bad[r] - (r ? bad[l - 1] : 0);
		printf("%d\n", len / k - gg + bb);
	}
	return 0;
}
