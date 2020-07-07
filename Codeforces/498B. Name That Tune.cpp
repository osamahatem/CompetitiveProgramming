/*
 * 498B. Name That Tune.cpp
 *
 *  Created on: Aug 2, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

double dp[2][5005];
int n, T, t[5005], p[5005];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	scanf("%d%d", &n, &T);
	for (int i = 0; i < n; i++)
		scanf("%d%d", &p[i], &t[i]);
	bool cs = n % 2, ps = (n - 1) % 2;
	for (int s = n - 1; s >= 0; s--) {
		cs = !cs, ps = !ps;
		double ip = 1.0;
		for (int i = 0; i < t[s]; i++)
			ip *= (1.0 - p[s] / 100.0);
		for (int i = 1; i <= T; i++) {
			dp[cs][i] = dp[cs][i - 1] * (1.0 - p[s] / 100.0);
			dp[cs][i] += (1.0 + dp[ps][i - 1]) * (p[s] / 100.0);
			if (i > t[s])
				dp[cs][i] -= (1.0 + dp[ps][i - t[s] - 1]) * ip;
			if (i >= t[s])
				dp[cs][i] -= (1.0 + dp[ps][i - t[s]]) * -ip;
		}
	}
	printf("%.6f\n", dp[0][T]);
	return 0;
}
