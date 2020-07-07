/*
 * 621A. Wet Shark and Odd and Even.cpp
 *
 *  Created on: Mar 6, 2016
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

	int n, x, oddCount = 0, minOdd = 1e9;
	long long sum = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		sum += x;
		if (x % 2)
			oddCount++, minOdd = min(minOdd, x);
	}
	if (oddCount % 2)
		sum -= minOdd;
	printf("%lld\n", sum);
	return 0;
}
