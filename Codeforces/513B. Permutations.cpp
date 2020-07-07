/*
 * 513B. Permutations.cpp
 *
 *  Created on: Feb 7, 2015
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
	long long m;
	vector<int> ans;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		ans.push_back(i);
	if (n == 1) {
		cout << "1" << endl;
		return 0;
	}
	m--;
	for (int i = 0; i < n; i++) {
		if (m & (1ll << i)) {
			for (int x = n - 1 - i; x < n; x++)
				swap(ans[x], ans[x - 1]);
		}
	}
	for (int i = 0; i < n; i++) {
		if (i)
			cout << " ";
		cout << ans[i];
	}
	cout << endl;
	return 0;
}
