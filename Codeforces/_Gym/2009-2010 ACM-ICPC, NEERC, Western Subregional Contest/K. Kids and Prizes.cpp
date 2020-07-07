/*
 * K. Kids and Prizes.cpp
 *
 *  Created on: Oct 3, 2017
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

	freopen("kids.in", "r", stdin);
	freopen("kids.out", "w", stdout);
	int n, m;
	double ans = 1.0;
	scanf("%d%d", &n, &m);
	for (int i = 2; i <= m; i++)
		ans = ans / n * ans + (n - ans) / n * (ans + 1.0);
	printf("%.9f\n", ans);
	return 0;
}
