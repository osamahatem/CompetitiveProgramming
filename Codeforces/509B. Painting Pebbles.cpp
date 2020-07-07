/*
 * 509B. Painting Pebbles.cpp
 *
 *  Created on: Feb 2, 2015
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

	int n, k, a[105], c = 0, flag;
	vector<int> ans[105];
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	while (c < k && flag < n) {
		flag = 0;
		for (int i = 0; i < n; i++) {
			if (a[i] == 0) {
				flag++;
				continue;
			}
			a[i]--;
			ans[i].push_back(c + 1);
		}
		if (flag)
			c++;
	}
	flag = 0;
	for (int i = 0; i < n; i++)
		flag += (a[i] ? 1 : 0);
	if (flag) {
		cout << "NO" << endl;
	} else {
		cout << "YES" << endl;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < (int) ans[i].size(); j++) {
				if (j)
					cout << " ";
				cout << ans[i][j];
			}
			cout << endl;
		}
	}
	return 0;
}
