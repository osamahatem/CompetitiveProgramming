/*
 * 58C. Trees.cpp
 *
 *  Created on: Aug 8, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1e5 + 5;

int cnt[MAXN];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n, x, ans = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		int d = (i < n / 2 ? i : n - 1 - i);
		x -= d;
		if (x < 1)
			continue;
		cnt[x]++;
		ans = max(ans, cnt[x]);
	}
	printf("%d\n", n - ans);
	return 0;
}
