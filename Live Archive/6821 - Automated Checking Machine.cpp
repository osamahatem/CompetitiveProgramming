/*
 * 6821 - Automated Checking Machine.cpp
 *
 *  Created on: Sep 21, 2015
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

	int d;
	while (scanf("%d", &d) != EOF) {
		int x = d, y = 0;
		for (int i = 1; i < 5; i++) {
			scanf("%d", &d);
			x = 2 * x + d;
		}
		for (int i = 0; i < 5; i++) {
			scanf("%d", &d);
			y = 2 * y + d;
		}
		if ((x ^ y) == 31)
			printf("Y\n");
		else
			printf("N\n");
	}
	return 0;
}
