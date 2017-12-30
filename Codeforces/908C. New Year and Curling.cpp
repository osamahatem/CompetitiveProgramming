/*
 * 908C. New Year and Curling.cpp
 *
 *  Created on: Dec 29, 2017
 *      Author: Osama Hatem
 */
 
/*
http://codeforces.com/blog/entry/56713
*/

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const double EPS = 1e-9;

int n;
double r, x[1005], y[1005];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	cout << fixed << setprecision(6);
	cin >> n >> r;
	for (int i = 0; i < n; i++) {
		cin >> x[i];
		y[i] = r;
		for (int j = 0; j < i; j++) {
			double dx = abs(x[i] - x[j]);
			if (dx > 2.0 * r + EPS)
				continue;
			y[i] = max(y[i], sqrt(4.0 * r * r - dx * dx) + y[j]);
		}
		if (i)
			cout << " ";
		cout << y[i];
	}
	cout << endl;
	return 0;
}
