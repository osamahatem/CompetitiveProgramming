/*
 * 515C. Drazil and Factorial.cpp
 *
 *  Created on: Feb 17, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int cnt[10];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n;
	long long a;
	cin >> n >> a;
	while (n--) {
		int x = a % 10;
		for (int i = 2; i <= x; i++) {
			int y = i;
			for (int j = 2; j * j <= y; j++) {
				while (y % j == 0) {
					cnt[j]++;
					y /= j;
				}
			}
			if (y > 1)
				cnt[y]++;
		}
		a /= 10;
	}
	vector<int> ans;
	for (int i = 9; i > 1; i--) {
		while (cnt[i]) {
			for (int x = 2; x <= i; x++) {
				int y = x;
				for (int j = 2; j * j <= y; j++) {
					while (y % j == 0) {
						cnt[j]--;
						y /= j;
					}
				}
				if (y > 1)
					cnt[y]--;
			}
			ans.push_back(i);
		}
	}
	for (int i = 0; i < (int) ans.size(); i++)
		cout << ans[i];
	cout << endl;
	return 0;
}
