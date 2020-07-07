/*
 * 617D. Polyline.cpp
 *
 *  Created on: Feb 19, 2016
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

	int x, y;
	set<int> xs, ys;
	pair<int, int> arr[3];
	for (int i = 0; i < 3; i++) {
		cin >> x >> y;
		arr[i].first = x, arr[i].second = y;
		xs.insert(x), ys.insert(y);
	}
	int ans = 3;
	for (int i = 0; i < 3; i++)
		for (int j = i + 1; j < 3; j++) {
			int mxx = max(arr[i].first, arr[j].first);
			int mnx = min(arr[i].first, arr[j].first);
			int mxy = max(arr[i].second, arr[j].second);
			int mny = min(arr[i].second, arr[j].second);
			if (arr[i].first == arr[j].first
					&& (arr[3 - i - j].second >= mxy
							|| arr[3 - i - j].second <= mny))
				ans = 2;
			else if (arr[i].second == arr[j].second
					&& (arr[3 - i - j].first >= mxx
							|| arr[3 - i - j].first <= mnx))
				ans = 2;
		}
	if (xs.size() == 1 || ys.size() == 1)
		ans = 1;
	cout << ans << endl;
	return 0;
}
