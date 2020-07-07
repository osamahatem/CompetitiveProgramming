/*
 * 736A. Tennis Championship.cpp
 *
 *  Created on: Nov 27, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

long long fib[100];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	fib[0] = 1, fib[1] = 2;
	long long n;
	scanf("%lld", &n);
	n -= 2;
	int ans = 1;
	for (int i = 2; fib[i - 1] <= n; i++)
		fib[i] = fib[i - 1] + fib[i - 2];
	for (int i = 0; n >= fib[i]; i++)
		ans++, n -= fib[i];
	printf("%d\n", ans);
	return 0;
}
