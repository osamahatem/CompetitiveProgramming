/*
 * 389A. Fox and Number Game.cpp
 *
 *  Created on: Jun 13, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int n, arr[105];

int getMin() {
	int mini = arr[0];
	for (int i = 1; i < n; i++)
		mini = min(mini, arr[i]);
	return mini;
}

bool check() {
	for (int i = 1; i < n; i++)
		if (arr[i] != arr[i - 1])
			return false;
	return true;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	while (!check()) {
		int x = getMin();
		for (int i = 0; i < n; i++) {
			arr[i] %= x;
			if (!arr[i])
				arr[i] += x;
		}
	}
	cout << n * arr[0] << endl;
	return 0;
}
