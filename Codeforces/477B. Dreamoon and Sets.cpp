/*
 * 477B. Dreamoon and Sets.cpp
 *
 *  Created on: Oct 12, 2014
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
//	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n, k;
	cin >> n >> k;
	cout << k * (6 * n - 1) << "\n";
	for (int i = 0; i < n; i++)
		cout << k * (6 * i + 1) << " " << k * (6 * i + 2) << " "
				<< k * (6 * i + 3) << " " << k * (6 * i + 5) << "\n";
	return 0;
}
