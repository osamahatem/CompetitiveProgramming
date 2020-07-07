/*
 * 12488 - Start Grid.cpp
 *
 *  Created on: Aug 24, 2014
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

	int n;
	while (cin >> n) {
		vector<int> st(n), en(n);
		int ans = 0;
		for (int i = 0; i < n; i++)
			cin >> st[i];
		for (int i = 0; i < n; i++) {
			cin >> en[i];
			for (int j = 0; j < n; j++) {
				if (st[j] == en[i]) {
					for (int k = 0; k < i; k++) {
						bool flag = 1;
						for (int l = 0; l < j; l++) {
							if (en[k] == st[l]) {
								flag = 0;
								break;
							}
						}
						ans += flag;
					}
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
