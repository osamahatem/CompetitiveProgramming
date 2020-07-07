/*
 * 482A. Diverse Permutation.cpp
 *
 *  Created on: Oct 24, 2014
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

	int n, k;
	cin >> n >> k;
	int l = 1, h = ++k;
	cout << l++ << " " << h--;
	while (l < h)
		cout << " " << l++ << " " << h--;
	if (l == h)
		cout << " " << l;
	while (++k <= n)
		cout << " " << k;
	cout << endl;
	return 0;
}
