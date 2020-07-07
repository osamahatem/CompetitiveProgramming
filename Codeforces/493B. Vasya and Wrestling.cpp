/*
 * 493B. Vasya and Wrestling.cpp
 *
 *  Created on: Dec 3, 2014
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

	int n, a;
	bool last;
	long long sum1 = 0, sum2 = 0;
	vector<int> f, l;
	cin >> n;
	while (n--) {
		cin >> a;
		if (a > 0) {
			last = 0;
			sum1 += a;
			f.push_back(a);
		} else {
			last = 1;
			sum2 -= a;
			l.push_back(-a);
		}
	}
	if (sum1 != sum2)
		cout << (sum1 > sum2 ? "first" : "second") << endl;
	else {
		int sz1 = f.size(), sz2 = l.size();
		for (int i = 0; i < min(sz1, sz2); i++)
			if (f[i] != l[i]) {
				cout << (f[i] > l[i] ? "first" : "second") << endl;
				return 0;
			}
		if (sz1 != sz2)
			cout << (sz1 > sz2 ? "first" : "second") << endl;
		else
			cout << (last ? "second" : "first") << endl;
	}
	return 0;
}
