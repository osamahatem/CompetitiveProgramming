/*
 * 490A. Team Olympiad.cpp
 *
 *  Created on: Nov 23, 2014
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

	int n, x;
	vector<int> arr[4];
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> x;
		arr[x].push_back(i);
	}
	int w = min(arr[1].size(), min(arr[2].size(), arr[3].size()));
	cout << w << endl;
	for (int i = 0; i < w; i++)
		cout << arr[1][i] << " " << arr[2][i] << " " << arr[3][i] << endl;
	return 0;
}
