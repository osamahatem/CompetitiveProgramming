/*
 * 847A. Union of Doubly Linked Lists.cpp
 *
 *  Created on: Sep 27, 2017
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int n, l[105], r[105];
vector<vector<int>> all;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d%d", &l[i], &r[i]);
	for (int i = 1; i <= n; i++) {
		if (l[i])
			continue;
		all.push_back(vector<int>());
		int cur = i;
		while (cur) {
			all.back().push_back(cur);
			cur = r[cur];
		}
	}
	for (int i = 0; i + 1 < (int) all.size(); i++) {
		int a = all[i].back(), b = all[i + 1][0];
		r[a] = b, l[b] = a;
	}
	for (int i = 1; i <= n; i++)
		printf("%d %d\n", l[i], r[i]);
	return 0;
}
