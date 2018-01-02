/*
 * 2369 - Two Cylinders.cpp
 *
 *  Created on: Jan 2, 2018
 *      Author: Osama Hatem
 */
 
/*
The cross section area is a rectangle of sides sqrt(r1 * r1 - z * z) and
sqrt(r2 * r2 - z * z), where z is the dimension perpendicular to both cylinders'
axes. Use Simpson's to integrate this surface area.
Refer to the following link for visualisation:
https://math.stackexchange.com/questions/494249/find-the-volume-common-to-two-circular-cylinders-each-with-radius-r-if-the-axe
*/

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const double dz = 1e-5;

double r1, r2;

double f(double z) {
	return sqrt(r1 * r1 - z * z) * sqrt(r2 * r2 - z * z);
}

double simpsons(double a, double b) {
	return (b - a) / 6.0 * (f(a) + f(b) + 4.0 * f((a + b) / 2.0));
}

int main() {
//#ifndef ONLINE_JUDGE
//	freopen("in.in", "r", stdin);
////	freopen("out.out", "w", stdout);
//#endif

	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cout << fixed << setprecision(4);

	int T;
	cin >> T;
	while (T--) {
		cin >> r1 >> r2;
		if (r2 < r1)
			swap(r1, r2);
		double ans = 0.0;
		for (double z = 0.0; z + dz < r1; z += dz)
			ans += simpsons(z, z + dz);
		ans *= 8.0;
		cout << ans << endl;
		if (T)
			cout << endl;
	}
	return 0;
}
