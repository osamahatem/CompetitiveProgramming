/*
 * 704A. Thor.cpp
 *
 *  Created on: Aug 7, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

map<int, queue<int>> app;
set<pair<int, int>> all;
int t;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n, q;
	scanf("%d%d", &n, &q);
	int cnt = 0;
	while (q--) {
		int ty, x;
		scanf("%d%d", &ty, &x);
		if (ty == 1) {
			app[x].push(++t);
			all.insert(make_pair(t, x));
			cnt++;
		} else if (ty == 2) {
			if (app.count(x))
				while (app[x].size()) {
					all.erase(make_pair(app[x].front(), x));
					cnt--;
					app[x].pop();
				}
		} else {
			while (all.size() && all.begin()->first <= x) {
				app[all.begin()->second].pop();
				all.erase(all.begin());
				cnt--;
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}
