/*
 * 736B. Taxes.cpp
 *
 *  Created on: Nov 27, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

bool isPrime(int x) {
	if (x < 2)
		return false;
	for (int i = 2; i <= x / i; i++)
		if (x % i == 0)
			return false;
	return true;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n, ans = 3;
	scanf("%d", &n);
	if (isPrime(n))
		ans = 1;
	else if (n % 2 == 0 || isPrime(n - 2))
		ans = 2;
	printf("%d\n", ans);
	return 0;
}
