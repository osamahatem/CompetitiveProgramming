/*
 * 490D. Chocolate.cpp
 *
 *  Created on: Nov 23, 2014
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

	int a1, b1, a2, b2;
	long long a, b;
	cin >> a1 >> b1 >> a2 >> b2;
	a = (long long) a1 * b1;
	b = (long long) a2 * b2;
	int c12 = 0, c13 = 0, c22 = 0, c23 = 0;
	while (a % 2 == 0)
		a /= 2, c12++;
	while (a % 3 == 0)
		a /= 3, c13++;
	while (b % 2 == 0)
		b /= 2, c22++;
	while (b % 3 == 0)
		b /= 3, c23++;
	if (a != b) {
		cout << "-1\n";
		return 0;
	}

	int ans = abs(c13 - c23);
	if (c13 >= c23) {
		int c = c13 - c23;
		while (c && a1 % 3 == 0) {
			c--;
			a1 = a1 / 3 * 2;
			c12++;
		}
		while (c && b1 % 3 == 0) {
			c--;
			b1 = b1 / 3 * 2;
			c12++;
		}
	} else {
		int c = c23 - c13;
		while (c && a2 % 3 == 0) {
			c--;
			a2 = a2 / 3 * 2;
			c22++;
		}
		while (c && b2 % 3 == 0) {
			c--;
			b2 = b2 / 3 * 2;
			c22++;
		}
	}

	ans += abs(c12 - c22);
	if (c12 >= c22) {
		int c = c12 - c22;
		while (c && a1 % 2 == 0) {
			c--;
			a1 /= 2;
		}
		while (c && b1 % 2 == 0) {
			c--;
			b1 /= 2;
		}
	} else {
		int c = c22 - c12;
		while (c && a2 % 2 == 0) {
			c--;
			a2 /= 2;
		}
		while (c && b2 % 2 == 0) {
			c--;
			b2 /= 2;
		}
	}
	cout << ans << endl;
	cout << a1 << " " << b1 << endl;
	cout << a2 << " " << b2 << endl;
	return 0;
}
