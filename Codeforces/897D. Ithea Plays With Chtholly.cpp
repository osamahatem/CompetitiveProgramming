/*
 * 897D. Ithea Plays With Chtholly.cpp
 *
 *  Created on: Dec 2, 2017
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int n, m, c, arr[1005];

bool check() {
	for (int i = 1; i <= n; i++)
		if (!arr[i] || arr[i] < arr[i - 1])
			return false;
	return true;
}

int fromRight(int x) {
	int idx = n;
	while (idx && arr[idx] >= x)
		idx--;
	arr[idx] = x;
	return idx;
}

int fromLeft(int x) {
	int idx = 1;
	while (idx <= n && arr[idx] && arr[idx] <= x)
		idx++;
	arr[idx] = x;
	return idx;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	cin >> n >> m >> c;
	while (m && !check()) {
		int x;
		cin >> x;
		if (x > c / 2)
			cout << fromRight(x) << endl;
		else
			cout << fromLeft(x) << endl;
		m--;
	}
	return 0;
}
