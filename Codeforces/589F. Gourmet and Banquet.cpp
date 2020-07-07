/*
 * 589F. Gourmet and Banquet.cpp
 *
 *  Created on: Oct 18, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int n;
pair<int, int> all[105];

bool check(int x) {
	if (!x)
		return true;
	int cur = 0;
	multiset<pair<int, int>> s;
	for (int i = 0; i <= 10000; i++) {
		while (cur < n && all[cur].first <= i)
			s.insert(make_pair(all[cur++].second, 0));
		if (s.empty())
			continue;
		if (s.begin()->first <= i)
			return false;
		pair<int, int> temp = *(s.begin());
		s.erase(s.begin());
		temp.second++;
		if (temp.second == x)
			continue;
		s.insert(temp);
	}
	return true;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> all[i].first >> all[i].second;
	sort(all, all + n);
	int s = 0, e = 10000;
	while (s < e) {
		int mid = (s + e + 1) / 2;
		if (check(mid))
			s = mid;
		else
			e = mid - 1;
	}
	cout << s * n << endl;
	return 0;
}
