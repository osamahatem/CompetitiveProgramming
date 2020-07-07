/*
 * 518D. Ilya and Escalator.cpp
 *
 *  Created on: Feb 24, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

double pro[2005][2005];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n, t;
	double p;
	cin >> n >> p >> t;
	for (int i = 0; i <= n; i++)
		pro[t][i] = i;
	for (int i = t - 1; i >= 0; i--) {
		for (int j = 0; j < n; j++)
			pro[i][j] = (1.0 - p) * pro[i + 1][j] + p * pro[i + 1][j + 1];
		pro[i][n] = pro[i + 1][n];
	}
	cout << fixed << setprecision(6) << pro[0][0] << endl;
	return 0;
}
