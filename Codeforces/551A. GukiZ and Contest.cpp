/*
 * 551A. GukiZ and Contest.cpp
 *
 *  Created on: Jun 12, 2015
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

	int n, ans[2005];
	pair<int, int> in[2005];
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> in[i].first;
		in[i].second = i;
	}
	sort(in, in + n, greater<pair<int, int> >());
	ans[in[0].second] = 1;
	for (int i = 1; i < n; i++) {
		ans[in[i].second] = ans[in[i - 1].second];
		if (in[i].first < in[i - 1].first)
			ans[in[i].second] = i + 1;
	}
	for (int i = 0; i < n; i++) {
		if (i)
			cout << " ";
		cout << ans[i];
	}
	cout << endl;
	return 0;
}
