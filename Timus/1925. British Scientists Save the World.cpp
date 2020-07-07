/*
 * 1925. British Scientists Save the World.cpp
 *
 *  Created on: Aug 6, 2014
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

	int n, k, diff, sum, x, y;
	scanf("%d%d", &n, &k);
	sum = k;
	diff = (n + 1) * 2;
	while (n--) {
		scanf("%d%d", &x, &y);
		sum += x - y;
	}
	if (sum - diff >= 0)
		printf("%d\n", sum - diff);
	else
		printf("Big Bang!\n");
	return 0;
}
