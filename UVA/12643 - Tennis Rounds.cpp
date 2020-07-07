/*
 * 12643 - Tennis Rounds.cpp
 *
 *  Created on: Aug 11, 2014
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

	int n, a, b;
	while (scanf("%d%d%d", &n, &a, &b) != EOF) {
		int r = 0;
		while (a != b) {
			a = (a + 1) / 2;
			b = (b + 1) / 2;
			r++;
		}
		printf("%d\n", r);
	}
	return 0;
}
