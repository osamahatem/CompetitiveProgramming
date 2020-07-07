/*
 * 706A. Beru-taxi.cpp
 *
 *  Created on: Aug 11, 2016
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

	int n, a, b, x, y, v;
	double mini = 1e9;
	cin >> a >> b >> n;
	while (n--) {
		cin >> x >> y >> v;
		int dx = x - a, dy = y - b;
		double d = sqrt(dx * dx + dy * dy);
		mini = min(mini, d / v);
	}
	cout << fixed << setprecision(6) << mini << endl;
	return 0;
}
