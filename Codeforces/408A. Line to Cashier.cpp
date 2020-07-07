/*
 * 408A. Line to Cashier.cpp
 *
 *  Created on: May 15, 2015
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

	int n, k[105], mini = 1 << 28;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> k[i];
	for (int i = 0; i < n; i++) {
		int temp = 0, it;
		for (int j = 0; j < k[i]; j++) {
			cin >> it;
			temp += 5 * it + 15;
		}
		mini = min(mini, temp);
	}
	cout << mini << endl;
	return 0;
}
