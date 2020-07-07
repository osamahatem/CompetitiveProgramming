/*
 * 573A. Bear and Poker.cpp
 *
 *  Created on: Aug 29, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1e5 + 5;

int arr[MAXN];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n, g;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		while (arr[i] % 2 == 0)
			arr[i] /= 2;
		while (arr[i] % 3 == 0)
			arr[i] /= 3;
		if (arr[0] != arr[i]) {
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;
	return 0;
}
