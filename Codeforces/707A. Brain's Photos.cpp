/*
 * 707A. Brain's Photos.cpp
 *
 *  Created on: Aug 24, 2016
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

	int n, m;
	char c;
	cin >> n >> m;
	while (n--) {
		for (int i = 0; i < m; i++) {
			cin >> c;
			if (c == 'C' || c == 'M' || c == 'Y') {
				printf("#Color\n");
				return 0;
			}
		}
	}
	printf("#Black&White\n");
	return 0;
}
