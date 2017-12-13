/*
 * 10357 - Playball !!!.cpp
 *
 *  Created on: Dec 13, 2017
 *      Author: Osama Hatem
 */
 
/*
Just calculate t at which the ball hits the ground, then check if any player can
catch the ball and whether it is a foul. I used binary search just to avoid
using doubles, but t can be obtained without it.
*/

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int n, x[20], y[20], v[20];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	scanf("PLAYERS=%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d%d%d", &x[i], &y[i], &v[i]);
	int T;
	scanf("%*cBALLS=%d", &T);
	for (int t = 1; t <= T; t++) {
		int a, b, c, d, e, g, f;
		scanf("%d%d%d%d%d%d%d", &a, &b, &c, &d, &e, &g, &f);
		int st = 1, en = 1e6;
		while (st < en) {
			int mid = (st + en) / 2;
			long long z = 1ll * a * mid * mid + 1ll * b * mid + c;
			if (z > 0)
				st = mid + 1;
			else
				en = mid;
		}
		long long xx = 1ll * d * st + e, yy = 1ll * g * st + f;
		string ans = "safe";
		if (xx < 0 || yy < 0)
			ans = "foul";
		else {
			for (int i = 0; i < n; i++) {
				long long dx = xx - x[i], dy = yy - y[i];
				long long dist = dx * dx + dy * dy;
				if (dist <= 1ll * v[i] * v[i] * st * st)
					ans = "caught";
			}
		}
		printf("Ball %d was %s at (%lld,%lld)\n", t, ans.c_str(), xx, yy);
	}
	return 0;
}
