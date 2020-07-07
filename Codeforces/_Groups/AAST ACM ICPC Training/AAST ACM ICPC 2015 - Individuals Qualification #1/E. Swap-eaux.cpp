/*
 * E. Swap-eaux.cpp
 *
 *  Created on: Sep 6, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int arr[1005];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	freopen("swapeaux.in", "r", stdin);
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		int n, ans = 0;
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> arr[i];
		for (int i = 0; i < n; i++) {
			int mini = arr[i], idx = i;
			for (int j = i + 1; j < n; j++)
				if (arr[j] < mini)
					mini = arr[j], idx = j;
			if (idx != i)
				swap(arr[i], arr[idx]), ans++;
		}
		cout << "Case " << t << ": " << ans << "\n";
	}
	return 0;
}
