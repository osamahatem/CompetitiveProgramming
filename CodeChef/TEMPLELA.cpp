/*
 * TEMPLELA.cpp
 *
 *  Created on: May 20, 2017
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int T;
	scanf("%d", &T);
	while (T--) {
		int n, h;
		scanf("%d", &n);
		bool ans = n & 1;
		int mid = (n + 1) / 2;
		for (int i = 1; i <= n; i++) {
			scanf("%d", &h);
			if ((i <= mid && h != i) || (i > mid && h != mid + mid - i))
				ans = 0;
		}
		printf("%s\n", ans ? "yes" : "no");
	}
	return 0;
}
