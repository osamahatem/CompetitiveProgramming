/*
 * G. Graduation Projects (A).cpp
 *
 *  Created on: Sep 3, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n, gr[105];
	cin >> n;
	double avg = 0, ans = 0;
	for (int i = 0; i < n; i++) {
		cin >> gr[i * 2] >> gr[i * 2 + 1];
		avg += (gr[i * 2] + gr[i * 2 + 1]) / (double) n;
	}
	for (int i = 0; i < n; i++)
		ans += abs(gr[i * 2] + gr[i * 2 + 1] - avg);
	cout << fixed << setprecision(9) << ans << endl;
	return 0;
}
