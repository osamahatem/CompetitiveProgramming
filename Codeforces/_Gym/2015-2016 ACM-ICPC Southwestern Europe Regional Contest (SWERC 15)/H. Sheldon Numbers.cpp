/*
 * H. Sheldon Numbers.cpp
 *
 *  Created on: Oct 1, 2017
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

long long x, y;
set<long long> ans;

long long solve(int a, int b) {
	if (!b) {
		long long t = (1ll << a) - 1;
		if (t >= x && t <= y)
			ans.insert(t);
	}
	long long t = 0;
	for (int i = 1; (y >> (i & 1 ? a : b)) >= t; i++) {
		t = t << (i & 1 ? a : b);
		if (i & 1)
			t |= (1ll << a) - 1;
		if (t >= x && t <= y)
			ans.insert(t);
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	cin >> x >> y;
	for (int i = 1; i < 64; i++)
		for (int j = 0; i + j < 64; j++)
			solve(i, j);
	cout << ans.size() << endl;
	return 0;
}
