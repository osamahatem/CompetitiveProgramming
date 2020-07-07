/*
 ID: 19semse1
 PROG: sprime
 LANG: C++
 */
/*
 * sprime.cpp
 *
 *  Created on: Feb 27, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

bool isPrime(int x) {
	for (int i = 2; i * i <= x; i++)
		if (x % i == 0)
			return false;
	return x > 1;
}

void solve(int n, int rib, bool flag) {
	if (flag && !isPrime(rib))
		return;
	if (!n) {
		cout << rib << endl;
		return;
	}
	for (int i = 0; i < 10; i++)
		solve(n - 1, rib * 10 + i, 1);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("sprime.in", "r", stdin);
	freopen("sprime.out", "w", stdout);
#endif

	int n;
	cin >> n;
	solve(n, 0, 0);
	return 0;
}
