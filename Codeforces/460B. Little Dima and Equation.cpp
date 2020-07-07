/*
 * 460B. Little Dima and Equation.cpp
 *
 *  Created on: Aug 20, 2014
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

long long power(int b, int p) {
	long long ret = 1;
	while (p--)
		ret *= b;
	return ret;
}

int sum(long long x) {
	int ret = 0;
	while (x) {
		ret += x % 10;
		x /= 10;
	}
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	long long a, b, c;
	set<long long> all;
	set<long long>::iterator it;
	cin >> a >> b >> c;
	for (int i = 1; i <= 81; i++) {
		long long temp = b * power(i, a) + c;
		if (temp > 0 && temp < 1000000000 && sum(temp) == i)
			all.insert(temp);
	}
	cout << all.size() << "\n";
	for (it = all.begin(); it != all.end(); it++) {
		if (it != all.begin())
			cout << " ";
		cout << *it;
	}
	return 0;
}
