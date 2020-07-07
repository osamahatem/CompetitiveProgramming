/*
 * 2096 - Collecting Bugs.cpp
 *
 *  Created on: Nov 8, 2017
 *      Author: Osama Hatem
 */

//#include <bits/stdtr1c++.h>
//#include <ext/numeric>
#include <iostream>
#include <iomanip>

using namespace std;

double dp[1005][1005];
bool vis[1005][1005];
int N, S;

double solve(int n, int s) {
	if (!n && !s)
		return 0.0;
	double &ret = dp[n][s];
	if (vis[n][s])
		return ret;
	vis[n][s] = 1;
	ret = 0.0;
	if (n)
		ret += (1.0 + solve(n - 1, s)) * n / N * (S - s) / S;
	if (s)
		ret += (1.0 + solve(n, s - 1)) * (N - n) / N * s / S;
	if (n && s)
		ret += (1.0 + solve(n - 1, s - 1)) * n / N * s / S;
	ret += 1.0 * (N - n) / N * (S - s) / S;
	ret /= 1.0 - 1.0 * (N - n) / N * (S - s) / S;
	return ret;
}

int main() {
//#ifndef ONLINE_JUDGE
//	freopen("in.in", "r", stdin);
////	freopen("out.out", "w", stdout);
//#endif

	cin >> N >> S;
	cout << fixed << setprecision(4);
	cout << solve(N, S) << endl;
	return 0;
}
