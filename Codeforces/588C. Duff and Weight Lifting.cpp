/*
 * 588C. Duff and Weight Lifting.cpp
 *
 *  Created on: Oct 15, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int w[1000050];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n, ans = 0, x;
	scanf("%d", &n);
	while (n--) {
		scanf("%d", &x);
		w[x]++;
	}
	for (int i = 0; i < 1000050; i++) {
		w[i + 1] += w[i] / 2;
		ans += w[i] & 1;
	}
	printf("%d\n", ans);
	return 0;
}
