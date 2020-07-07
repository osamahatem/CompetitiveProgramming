/*
 * E. Equal Digits.cpp
 *
 *  Created on: Oct 4, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const long long MAXN = 1e15 + 5;

long long n, N, D;

int check(long long base) {
	if (base < 2)
		return -1;
	long long x = n;
	int ret = 0;
	while (x && x % base == D)
		ret++, x /= base;
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	cin >> n >> D;
	if (n == D) {
		cout << max(2ll, n + 1) << " 1" << endl;
		return 0;
	}
	if (n < D) {
		cout << "2 0" << endl;
		return 0;
	}
	N = n - D;
	long long k = 2, x = 0;
	for (int i = 1; i <= N / i; i++) {
		if (N % i == 0) {
			int xx = check(i);
			if ((xx > x) || (xx == x && i < k))
				x = xx, k = i;
			xx = check(N / i);
			if ((xx > x) || (xx == x && N / i < k))
				x = xx, k = N / i;
		}
	}
	cout << k << " " << x << endl;
	return 0;
}
