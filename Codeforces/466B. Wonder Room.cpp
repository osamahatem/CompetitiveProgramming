/*
 * 466B. Wonder Room.cpp
 *
 *  Created on: Jun 21, 2015
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

	long long n, a, b;
	cin >> n >> a >> b;
	n *= 6;
	if (n <= a * b) {
		cout << a * b << endl << a << " " << b << endl;
		return 0;
	}
	bool flag = 0;
	if (b < a)
		swap(a, b), flag = 1;
	long long na = 1 << 30, nb = 1 << 30;
	for (int aa = a; aa <= n / aa; aa++) {
		long long bb = (n + aa - 1) / aa;
		if (bb >= b && aa * bb < na * nb)
			na = aa, nb = bb;
	}
	if (flag)
		swap(na, nb);
	cout << na * nb << endl << na << " " << nb << endl;
	return 0;
}
