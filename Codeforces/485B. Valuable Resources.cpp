/*
 * 485B. Valuable Resources.cpp
 *
 *  Created on: Nov 5, 2014
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int INF = 1 << 30;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	long long x, y, minX = INF, minY = INF, maxX = -INF, maxY = -INF;
	int n;
	cin >> n;
	while (n--) {
		cin >> x >> y;
		minX = min(x, minX);
		maxX = max(x, maxX);
		minY = min(y, minY);
		maxY = max(y, maxY);
	}
	long long maxi = max(maxX - minX, maxY - minY);
	cout << maxi * maxi << endl;
	return 0;
}
