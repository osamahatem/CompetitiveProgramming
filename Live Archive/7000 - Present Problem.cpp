/*
 * 7000 - Present Problem.cpp
 *
 *  Created on: Nov 15, 2015
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

	int t;
	scanf("%d", &t);
	while (t--) {
		int n, m, l;
		scanf("%d%d%d", &n, &m, &l);
		set<pair<int, int>> all;
		while (m--) {
			int i, k;
			scanf("%d%d", &i, &k);
			all.insert(make_pair(k, i));
		}
		vector<int> ans, cur;
		for (int i = 0; i < n; i++)
			ans.push_back(0), cur.push_back(i);
		for (auto i = all.begin(); i != all.end(); i++)
			swap(cur[i->second], cur[i->second + 1]);
		for (int i = 0; i < (int) cur.size(); i++)
			ans[cur[i]] = i;
		for (int i = 0; i < (int) ans.size(); i++)
			printf("%d\n", ans[i]);
	}
	return 0;
}
