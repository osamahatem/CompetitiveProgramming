/*
 * PROSJEK.cpp
 *
 *  Created on: Oct 18, 2014
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
//	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n;
	long long sum = 0, x;
	cin >> n;
	vector<long long> ans;
	for (int i = 1; i <= n; i++) {
		cin >> x;
		ans.push_back(x * i - sum);
		sum += ans.back();
	}
	for (int i = 0; i < n; i++) {
		if (i)
			cout << " ";
		cout << ans[i];
	}
	cout << "\n";
	return 0;
}
