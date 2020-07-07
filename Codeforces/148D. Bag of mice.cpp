/*
 * 148D. Bag of mice.cpp
 *
 *  Created on: Nov 7, 2017
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

double dp[1005][1005];
bool vis[1005][1005];
int W, B;

double solve(int w, int b) {
	if (!w && !b)
		return (W + B) % 3 == 1 ? 1.0 : 0.0;
	double &ret = dp[w][b];
	if (vis[w][b])
		return ret;
	vis[w][b] = 1;
	ret = 1.0 * w / (w + b);
	if ((W + B - w - b) % 3 == 1) {
		if (b > 1)
			ret += 1.0 * b * (b - 1) / (w + b) / (w + b - 1)
					* (1.0 - solve(w, b - 2));
		if (b && w)
			ret += 1.0 * b * w / (w + b) / (w + b - 1)
					* (1.0 - solve(w - 1, b - 1));
		else if (b)
			ret += 1.0 * b / (w + b) * (1.0 - solve(w, b - 1));
	} else if (b)
		ret += 1.0 * b / (w + b) * (1.0 - solve(w, b - 1));
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	cin >> W >> B;
	cout << fixed << setprecision(9);
	cout << solve(W, B) << endl;
	return 0;
}
