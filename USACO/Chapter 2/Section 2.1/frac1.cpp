/*
 ID: 19semse1
 PROG: frac1
 LANG: C++
 */
/*
 * frac1.cpp
 *
 *  Created on: Mar 7, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

struct frac {
	int a, b;

	const bool operator <(const frac &t) const {
		int a1 = a * t.b, a2 = t.a * b;
		return a1 < a2;
	}
};

set<frac> all;

int main() {
//#ifndef ONLINE_JUDGE
	freopen("frac1.in", "r", stdin);
	freopen("frac1.out", "w", stdout);
//#endif

	int n;
	cin >> n;
	all.insert(frac { 0, 1 });
	for (int i = 1; i <= n; i++)
		for (int j = i; j <= n; j++) {
			int g = __gcd(i, j);
			all.insert(frac { i / g, j / g });
		}
	for (set<frac>::iterator it = all.begin(); it != all.end(); it++)
		cout << it->a << "/" << it->b << endl;
	return 0;
}
