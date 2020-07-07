/*
 * 588A. Duff and Meat.cpp
 *
 *  Created on: Oct 15, 2015
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

	int n, a, p, ans = 0, mini = 105;
	scanf("%d", &n);
	while (n--) {
		scanf("%d%d", &a, &p);
		mini = min(mini, p);
		ans += a * mini;
	}
	printf("%d\n", ans);
	return 0;
}
