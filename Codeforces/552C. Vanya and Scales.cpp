/*
 * 552C. Vanya and Scales.cpp
 *
 *  Created on: Jun 18, 2015
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

	int w, m;
	cin >> w >> m;
	while (m) {
		int mod = m % w;
		m /= w;
		if (mod > 1 && mod < w - 1) {
			cout << "NO" << endl;
			return 0;
		}
		if (mod == w - 1 && w > 2)
			m++;
	}
	cout << "YES" << endl;
	return 0;
}
