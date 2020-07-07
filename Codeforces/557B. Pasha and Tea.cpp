/*
 * 557B. Pasha and Tea.cpp
 *
 *  Created on: Jun 30, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 2e5 + 5;

int cup[MAXN];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n, w;
	cin >> n >> w;
	for (int i = 0; i < n * 2; i++)
		cin >> cup[i];
	sort(cup, cup + n * 2);
	double ans = min((double) cup[0], cup[n] / 2.0);
	ans = min(ans, w / (3.0 * n));
	ans *= 3.0 * n;
	cout << fixed << setprecision(7) << ans << endl;
	return 0;
}
