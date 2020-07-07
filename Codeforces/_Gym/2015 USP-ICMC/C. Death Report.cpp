/*
 * C. Death Report.cpp
 *
 *  Created on: Aug 30, 2015
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

	string x;
	cin >> x;
	long long num = 0, denum = 100;
	bool flag = 0;
	for (int i = 0; i < (int) x.size(); i++) {
		if (x[i] == '.') {
			flag = 1;
			continue;
		}
		num = num * 10 + x[i] - '0';
		if (flag)
			denum *= 10;
	}
	cout << denum / __gcd(num, denum) << endl;
	return 0;
}
