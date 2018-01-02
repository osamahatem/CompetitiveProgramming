/*
 * 1020. Rope.cpp
 *
 *  Created on: Jan 2, 2018
 *      Author: Osama Hatem
 */
 
/*
The length of the rope is equal to the perimeter of the polygon + the perimeter
of the nail, because ultimately, the rope will do exactly one full trip around
the nails' circumference.
*/

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const double PI = acos(-1.0);

double x[105], y[105];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int n;
	double r, ans = 0.0;
	cin >> n >> r;
	for (int i = 0; i < n; i++)
		cin >> x[i] >> y[i];
	x[n] = x[0], y[n] = y[0];
	for (int i = 0; i < n; i++)
		ans += hypot(x[i] - x[i + 1], y[i] - y[i + 1]);
	ans += 2.0 * PI * r;
	cout << fixed << setprecision(2) << ans << endl;
	return 0;
}
