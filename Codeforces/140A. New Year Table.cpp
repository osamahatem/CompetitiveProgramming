/*
 * 140A. New Year Table.cpp
 *
 *  Created on: Apr 23, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const double PI = acos(-1.0);
const double EPS = 1e-9;

int R, r;

bool check(int n) {
	double a1 = PI * (n - 2) / n;
	double a2 = PI - a1;
	a1 /= 2.0;
	double len = 2.0 * r * sin(a1) / sin(a2);
	return r + len - R < EPS;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n, maxi;
	cin >> n >> R >> r;
	if (r * 2 <= R) {
		maxi = 2;
		while (check(maxi + 1))
			maxi++;
	} else if (r <= R)
		maxi = 1;
	else
		maxi = 0;
	cout << (maxi < n ? "NO" : "YES") << endl;
	return 0;
}
