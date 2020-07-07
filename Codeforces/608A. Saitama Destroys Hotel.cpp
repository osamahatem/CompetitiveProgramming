/*
 * 608A. Saitama Destroys Hotel.cpp
 *
 *  Created on: Dec 23, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int n, s, maxT[1005];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int x, t;
	cin >> n >> s;
	while (n--) {
		cin >> x >> t;
		maxT[x] = max(maxT[x], t);
	}
	t = 0;
	for (; s > 0; s--) {
		t = max(t, maxT[s]);
		t++;
	}
	cout << t << endl;
	return 0;
}
