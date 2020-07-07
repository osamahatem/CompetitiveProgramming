/*
 *  Learn from Math.cpp
 *
 *  Created on: Sep 28, 2014
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

bool isComp(int x) {
	for (int i = 2; i * i <= x; i++)
		if (x % i == 0)
			return true;
	return false;
}

int main() {
#ifndef ONLINE_JUDGE
//	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n;
	cin >> n;
	for (int i = 2; i <= n / 2; i++)
		if (isComp(i) && isComp(n - i)) {
			cout << i << " " << n - i << "\n";
			break;
		}
	return 0;
}
