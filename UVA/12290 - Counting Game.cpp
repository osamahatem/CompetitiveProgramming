/*
 * 12290 - Counting Game.cpp
 *
 *  Created on: Aug 27, 2014
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

bool check(int x) {
	if (x % 7 == 0)
		return true;
	while (x) {
		if (x % 10 == 7)
			return true;
		x /= 10;
	}
	return false;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n, m, k;
	while (cin >> n >> m >> k, n) {
		int dir = 1, num = 1, cur = 1, clap = 0;
		while (clap < k) {
			if (cur == m && check(num))
				clap++;
			cur += dir;
			num++;
			if (cur == 1 || cur == n)
				dir *= -1;

		}
		cout << --num << "\n";
	}
	return 0;
}
