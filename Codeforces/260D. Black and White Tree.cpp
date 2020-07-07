/*
 * 260D. Black and White Tree.cpp
 *
 *  Created on: May 8, 2016
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
	vector<pair<int, int>> b, w;
	vector<pair<pair<int, int>, int>> ans;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int c, s;
		scanf("%d%d", &c, &s);
		if (c)
			b.push_back(make_pair(s, i));
		else
			w.push_back(make_pair(s, i));
	}
	for (int i = 0; i + 1 < n; i++) {
		pair<int, int> bb = b.back(), ww = w.back();
		int c = 0, mini = ww.first;
		if (bb.first < mini || (bb.first == mini && b.size() > w.size()))
			c = 1, mini = bb.first;
		ans.push_back(make_pair(make_pair(bb.second, ww.second), mini));
		b.back().first -= mini, w.back().first -= mini;
		if (c)
			b.pop_back();
		else
			w.pop_back();
	}
	for (int i = 0; i + 1 < n; i++)
		printf("%d %d %d\n", ++ans[i].first.first, ++ans[i].first.second,
				ans[i].second);
	return 0;
}
