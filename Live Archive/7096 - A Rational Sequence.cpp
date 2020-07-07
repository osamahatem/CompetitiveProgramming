/*
 * 7096 - A Rational Sequence.cpp
 *
 *  Created on: Sep 16, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int main() {
//#ifndef ONLINE_JUDGE
//	freopen("in.in", "r", stdin);
////	freopen("out.out", "w", stdout);
//#endif

	int T;
	cin >> T;
	while (T--) {
		int t, d = 0;
		unsigned int p, q;
		char ex;
		cin >> t >> p >> ex >> q;
		if (q == 1) {
			cout << t << " 1/" << p + 1 << endl;
			continue;
		}
		while (p > q)
			d++, p = p - q;
		q = q - p;
		p = q + p;
		while (d--)
			q = p + q;
		cout << t << " " << p << "/" << q << endl;
	}
	return 0;
}
