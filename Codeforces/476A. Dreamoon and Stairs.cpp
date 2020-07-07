/*
 * 476A. Dreamoon and Stairs.cpp
 *
 *  Created on: Jun 16, 2016
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

	int n, m;
	cin >> n >> m;
	int s = n / 2 + n % 2;
	int ans = (s + m - 1) / m * m;
	printf("%d\n", ans > n ? -1 : ans);
	return 0;
}
