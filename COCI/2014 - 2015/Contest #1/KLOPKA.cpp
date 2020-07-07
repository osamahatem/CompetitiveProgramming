/*
 * KLOPKA.cpp
 *
 *  Created on: Oct 18, 2014
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
//	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n, maxix = 0, minix = 100, maxiy = 0, miniy = 100, x, y;
	cin >> n;
	while (n--) {
		cin >> x >> y;
		maxix = max(maxix, x);
		minix = min(minix, x);
		maxiy = max(maxiy, y);
		miniy = min(miniy, y);
	}
	int maxi = max(maxix - minix, maxiy - miniy);
	cout << maxi * maxi << endl;
	return 0;
}
