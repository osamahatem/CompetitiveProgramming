/*
 * PIR.cpp
 *
 *  Created on: Dec 20, 2017
 *      Author: Osama Hatem
 */
 
/*
Used Heron-type formula for the volume of a tetrahedron.
*/

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

double U, V, W, u, v, w;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cout << fixed << setprecision(4);

	int t;
	cin >> t;
	while (t--) {
		cin >> w >> v >> u >> U >> V >> W;
		double X = (w - U + v) * (U + v + w);
		double x = (U - v + w) * (v - w + U);
		double Y = (u - V + w) * (V + w + u);
		double y = (V - w + u) * (w - u + V);
		double Z = (v - W + u) * (W + u + v);
		double z = (W - u + v) * (u - v + W);
		double a = sqrt(x * Y * Z);
		double b = sqrt(X * y * Z);
		double c = sqrt(X * Y * z);
		double d = sqrt(x * y * z);
		double ans = -a + b + c + d;
		ans *= a - b + c + d;
		ans *= a + b - c + d;
		ans *= a + b + c - d;
		ans = sqrt(ans) / (192.0 * u * v * w);
		cout << ans << endl;
	}
	return 0;
}
