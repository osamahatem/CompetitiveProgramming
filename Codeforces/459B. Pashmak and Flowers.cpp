/*
 * 459B. Pashmak and Flowers.cpp
 *
 *  Created on: Aug 15, 2014
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

	int n, x, maxi = 0, mini = 1 << 30;
	long long minCnt = 1, maxCnt = 1;
	cin >> n;
	while (n--) {
		cin >> x;
		if (x > maxi) {
			maxi = x;
			maxCnt = 1;
		} else if (x == maxi)
			maxCnt++;
		if (x < mini) {
			mini = x;
			minCnt = 1;
		} else if (x == mini)
			minCnt++;
	}
	if (maxi == mini) {
		cout << maxi - mini << " " << maxCnt * (maxCnt - 1) / 2 << "\n";
	} else
		cout << maxi - mini << " " << maxCnt * minCnt << "\n";
	return 0;
}
