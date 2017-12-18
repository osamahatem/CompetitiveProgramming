/*
 * spheres.cpp
 *
 *  Created on: Dec 18, 2017
 *      Author: Osama Hatem
 */
 
/*
Performed a ternary search to get the time at which the 2 spheres are the
closest together. If at that time, the distance between them is <= r1 + r2, then
the answer is 'YES', otherwise it's 'NO'. This problem can be solved in O(1),
but I felt this is simpler to implement and less bug-prone.
*/

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const double EPS = 1e-9;

double r[2], x[2], y[2], z[2], ax[2], ay[2], az[2];

double check(double t) {
	double nx[2], ny[2], nz[2];
	for (int i = 0; i < 2; i++) {
		nx[i] = x[i] + 0.5 * ax[i] * t * t;
		ny[i] = y[i] + 0.5 * ay[i] * t * t;
		nz[i] = z[i] + 0.5 * az[i] * t * t;
	}
	double temp = (nx[0] - nx[1]) * (nx[0] - nx[1]);
	temp += (ny[0] - ny[1]) * (ny[0] - ny[1]);
	temp += (nz[0] - nz[1]) * (nz[0] - nz[1]);
	return sqrt(temp);
}

int main() {
#ifndef ONLINE_JUDGE
//	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int T;
	cin >> T;
	while (T--) {
		for (int i = 0; i < 2; i++)
			cin >> r[i];
		for (int i = 0; i < 2; i++)
			cin >> x[i] >> y[i] >> z[i] >> ax[i] >> ay[i] >> az[i];

		double s = 0.0, e = 1e6;
		for (double sz = (e - s) * 2.0 / 3.0; sz > EPS; sz *= 2.0 / 3.0) {
			double m1 = s + sz / 2.0, m2 = s + sz;
			if (check(m2) < check(m1))
				s += sz / 2.0;
		}
		cout << (check(s) < r[0] + r[1] + EPS ? "YES" : "NO") << endl;
	}
	return 0;
}
