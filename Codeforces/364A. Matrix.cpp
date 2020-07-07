/*
 * 364A. Matrix.cpp
 *
 *  Created on: Apr 3, 2015
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

	int a;
	string in;
	vector<int> all, sums;
	long long ans = 0;
	cin >> a >> in;
	int sz = (int) in.size();
	for (int i = 0; i < sz; i++)
		all.push_back(in[i] - '0');
	for (int i = 0; i < sz; i++) {
		int sum = 0;
		for (int j = i; j < sz; j++) {
			sum += all[j];
			sums.push_back(sum);
		}
	}
	sort(sums.begin(), sums.end());
	for (int i = 0; i < (int) sums.size(); i++) {
		if (a == 0 && sums[i] == 0)
			ans += sums.size();
		else if (sums[i] > 0 && a % sums[i] == 0) {
			int y = upper_bound(sums.begin(), sums.end(), a / sums[i])
					- sums.begin();
			int x = lower_bound(sums.begin(), sums.end(), a / sums[i])
					- sums.begin();
			ans += y - x;
		}
	}
	cout << ans << endl;
	return 0;
}
