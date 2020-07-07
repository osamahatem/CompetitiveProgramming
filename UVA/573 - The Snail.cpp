/*
 * 573 - The Snail.cpp
 *
 *  Created on: Sep 28, 2014
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

	int h, u, d, f;
	while (cin >> h >> u >> d >> f, h) {
		double up = u, less = f / 100.0 * u, cur = 0.0;
		int day = 0;
		while (true) {
			++day;
			cur += up;
			if (cur > h)
				break;
			cur -= d;
			if (cur < 0)
				break;
			up -= less;
			if (up < 0)
				up = 0;
		}
		if (cur > h)
			cout << "success on day " << day << "\n";
		else
			cout << "failure on day " << day << "\n";
	}
	return 0;
}
