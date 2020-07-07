/*
 * 340B. Maximal Area Quadrilateral.cpp
 *
 *  Created on: Jan 30, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const double EPS = 1e-9;

struct point {
	int x, y;
};

double area(point a, point b, point c) {
	int x1 = b.x - a.x, y1 = b.y - a.y;
	int x2 = c.x - a.x, y2 = c.y - a.y;
	return 0.5 * (x1 * y2 - y1 * x2);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n;
	double ans = 0.0;
	point arr[305];
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i].x >> arr[i].y;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			double mini = 0.0, maxi = 0.0;
			for (int k = 0; k < n; k++) {
				double temp = area(arr[i], arr[j], arr[k]);
				mini = min(mini, temp), maxi = max(maxi, temp);
			}
			if (maxi < EPS || fabs(mini) < EPS)
				continue;
			ans = max(ans, maxi + fabs(mini));
		}
	}
	cout << fixed << setprecision(9) << ans << endl;
	return 0;
}
