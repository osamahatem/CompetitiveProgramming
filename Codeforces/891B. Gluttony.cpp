/*
 * 891B. Gluttony.cpp
 *
 *  Created on: Nov 17, 2017
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

	int n, arr[30], ans[30];
	pair<int, int> p[30];
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		p[i] = make_pair(arr[i], i);
	}
	sort(p, p + n);
	for (int i = 0; i < n; i++)
		ans[p[(i + 1) % n].second] = p[i].first;
	for (int i = 0; i + 1 < n; i++)
		cout << ans[i] << " ";
	cout << ans[n - 1] << endl;
	return 0;
}
