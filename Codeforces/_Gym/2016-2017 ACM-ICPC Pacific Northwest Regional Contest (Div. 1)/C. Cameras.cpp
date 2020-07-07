/*
 * C. Cameras.cpp
 *
 *  Created on: Oct 10, 2017
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1e5 + 5;

bool cam[MAXN];
int n, k, r;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	scanf("%d%d%d", &n, &k, &r);
	while (k--) {
		int x;
		scanf("%d", &x);
		cam[x] = 1;
	}
	int cur = 0, ans = 0;
	for (int i = 1; i <= r; i++)
		cur += cam[i];
	for (int i = 1; i + r - 1 <= n; i++) {
		for (int j = i + r - 1; cur < 2 && j >= i; j--)
			if (!cam[j])
				cam[j] = 1, cur++, ans++;
		cur += cam[i + r] - cam[i];
	}
	printf("%d\n", ans);
	return 0;
}
