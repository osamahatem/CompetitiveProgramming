/*
 * 459A. Pashmak and Garden.cpp
 *
 *  Created on: Aug 15, 2014
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

	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	if (abs(x2 - x1) != 0 && abs(y2 - y1) != 0) {
		if (abs(x2 - x1) != abs(y2 - y1))
			printf("-1\n");
		else
			printf("%d %d %d %d\n", x1, y2, x2, y1);
	} else if (abs(x2 - x1) == 0) {
		int d = y2 - y1;
		printf("%d %d %d %d\n", x1 + d, y1, x2 + d, y2);
	} else {
		int d = x2 - x1;
		printf("%d %d %d %d\n", x1, y1 + d, x2, y2 + d);
	}
	return 0;
}
