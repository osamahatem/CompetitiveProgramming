/*
 * 3273 - Lots of Sunlight.cpp
 *
 *  Created on: Jan 7, 2018
 *      Author: Osama Hatem
 */

/*
For each query, calculate the first angle at which the sun will fully cover the
apartment's eastern wall, and the last angle covering its western wall. This
represents sunlight hours, just convert it to time.
*/

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int rng = 12 * 3600 + 40 * 60;
const int st = 5 * 3600 + 37 * 60;
const int et = 18 * 3600 + 17 * 60;
const double PI = acosl(-1.0L);
const double EPS = 1e-9;

int n, w, h, m[105], d[105];

void print(int t) {
	int s = t % 60;
	t /= 60;
	int m = t % 60;
	t /= 60;
	cout << setw(2) << setfill('0') << t << ":";
	cout << setw(2) << setfill('0') << m << ":";
	cout << setw(2) << setfill('0') << s;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int t = 0;
	while (cin >> n, n) {
		cin >> w >> h;
		for (int i = 0; i < n; i++) {
			cin >> m[i];
			if (i + 1 < n)
				cin >> d[i];
		}
		cout << "Apartment Complex: " << ++t << endl << endl;
		int q;
		while (cin >> q, q) {
			int b = (q % 100) - 1, f = q / 100;
			cout << "Apartment " << q << ": ";
			if (b < 0 || b >= n || f == 0 || m[b] < f) {
				cout << "Does not exist";
			} else {
				double ang = 0.0;
				int x = 0;
				for (int i = b - 1; ~i; i--) {
					x += d[i];
					if (m[i] >= f)
						ang = max(ang, atan2((m[i] - f + 1) * h, x));
					x += w;
				}
				print((int) (ang / PI * rng + st + EPS));
				cout << " - ";
				ang = 0.0, x = 0;
				for (int i = b + 1; i < n; i++) {
					x += d[i - 1];
					if (m[i] >= f)
						ang = max(ang, atan2((m[i] - f + 1) * h, x));
					x += w;
				}
				print((int) (1.0L * et - ang / PI * rng + EPS));
			}
			cout << endl << endl;
		}
	}
	return 0;
}
