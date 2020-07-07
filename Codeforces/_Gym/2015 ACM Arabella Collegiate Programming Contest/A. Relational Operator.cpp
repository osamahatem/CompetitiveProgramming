/*
 * A. Relational Operator.cpp
 *
 *  Created on: Aug 29, 2015
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

	int t;
	cin >> t;
	while (t--) {
		int x, y;
		string op;
		cin >> x >> op >> y;
		if ((op == "!=" && x != y) || (op == "==" && x == y)
				|| (op == "<" && x < y) || (op == "<=" && x <= y)
				|| (op == ">" && x > y) || (op == ">=" && x >= y))
			cout << "true" << endl;
		else
			cout << "false" << endl;
	}
	return 0;
}
