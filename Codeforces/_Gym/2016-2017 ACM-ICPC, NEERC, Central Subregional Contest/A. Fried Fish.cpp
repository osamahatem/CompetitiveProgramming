/*
 * A. Fried Fish.cpp
 *
 *  Created on: Oct 19, 2017
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

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n, k;
	cin >> n >> k;
	cout << max(2, (n * 2 + k - 1) / k) << endl;
	return 0;
}
