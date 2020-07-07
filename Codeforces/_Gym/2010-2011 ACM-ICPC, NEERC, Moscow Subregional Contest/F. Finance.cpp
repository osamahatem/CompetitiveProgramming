/*
 * F. Finance.cpp
 *
 *  Created on: Oct 18, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int arr[4], temp[4], ans[4], mini = 300;

void solve() {
	int ret = 0, last = 52;
	for (int i = 0; i < 4; i++) {
		if (!i || temp[i] > temp[i - 1] + 1) {
			last = 52 - i;
			for (int j = 0; j < 4; j++)
				last -= (arr[j] >= temp[i]);
		}
		ret += last;
	}
	if (ret < mini) {
		mini = ret;
		for (int i = 0; i < 4; i++)
			ans[i] = temp[i];
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	for (int i = 0; i < 4; i++)
		cin >> arr[i];
	for (int i = 1; i <= 52; i++)
		for (int j = i + 1; j <= 52; j++)
			for (int k = j + 1; k <= 52; k++)
				for (int l = k + 1; l <= 52; l++) {
					temp[0] = i, temp[1] = j, temp[2] = k, temp[3] = l;
					solve();
				}
	cout << ans[0] << " " << ans[1] << " " << ans[2] << " " << ans[3] << endl;
	return 0;
}
