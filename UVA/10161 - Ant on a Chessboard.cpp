/*
 * 10161 - Ant on a Chessboard.cpp
 *
 *  Created on: Oct 2, 2014
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

	int n;
	while (cin >> n, n) {
		int ring = 1;
		while (ring * ring < n)
			ring++;
		int mid = ring * (ring - 1) + 1;
		int x = ring, y = ring;
		if (n < mid)
			x -= mid - n;
		if (n > mid)
			y -= n - mid;
		if (ring % 2)
			swap(x, y);
		cout << x << " " << y << "\n";
	}
	return 0;
}
