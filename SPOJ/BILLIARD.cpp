/*
 * BILLIARD.cpp
 *
 *  Created on: Dec 19, 2017
 *      Author: Osama Hatem
 */
 
/*
Calculate the total distance travelled by the ball in both directions, vertical
and horizontal, and use that to calculate the angle and the velocity.
*/

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const double PI = acos(-1.0);

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cout << fixed << setprecision(2);

	int a, b, s, m, n;
	while (cin >> a >> b >> s >> m >> n, a) {
		double ang = atan2(n * b, m * a) * 180.0 / PI;
		double vel = hypot(1.0 * a * m / s, 1.0 * b * n / s);
		cout << ang << " " << vel << endl;
	}
	return 0;
}
