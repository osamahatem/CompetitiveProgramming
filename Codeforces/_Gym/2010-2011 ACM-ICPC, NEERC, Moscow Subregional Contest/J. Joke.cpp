/*
 * J. Joke.cpp
 *
 *  Created on: Oct 18, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const long double EPS = 1e-11;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	long double x, y;
	cin >> x >> y;
	long long xx = (long long) ((x + EPS) * 1000000000);
	long long yy = (long long) ((y + EPS) * 1000000000);
	cout << xx / yy << endl;
	return 0;
}
