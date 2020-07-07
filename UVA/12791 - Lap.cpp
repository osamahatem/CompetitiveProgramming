/*
 * 12791 - Lap.cpp
 *
 *  Created on: Nov 10, 2014
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

	int x, y;
	while (cin >> x >> y) {
		set<int> ev;
		ev.insert(x);
		ev.insert(y);
		int p1 = 0, p2 = 0;
		while (p1 - p2 < 2) {
			int cur = *ev.begin();
			ev.erase(ev.begin());
			if (cur % x == 0)
				p1++, ev.insert(cur + x);
			else
				p2++, ev.insert(cur + y);
		}
		cout << p1 << endl;
	}
	return 0;
}
