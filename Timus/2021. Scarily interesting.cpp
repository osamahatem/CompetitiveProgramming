/*
 * 2021. Scarily interesting.cpp
 *
 *  Created on: Nov 8, 2014
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

	int n, sum1 = 0, sum2 = 0;
	cin >> n;
	vector<pair<int, int> > a1(n), a2(n);
	for (int i = 0; i < n; i++)
		cin >> a1[i].first, a1[i].second = i, sum1 += a1[i].first;
	for (int i = 0; i < n; i++)
		cin >> a2[i].first, a2[i].second = i, sum2 += a2[i].first;
	if (sum1 < sum2) {
		sort(a2.begin(), a2.end());
		sort(a1.begin(), a1.end(), greater<pair<int, int> >());
	} else {
		sort(a1.begin(), a1.end());
		sort(a2.begin(), a2.end(), greater<pair<int, int> >());
	}
	for (int i = 0; i < n; i++)
		cout << ++a1[i].second << " " << ++a2[i].second << endl;
	return 0;
}
