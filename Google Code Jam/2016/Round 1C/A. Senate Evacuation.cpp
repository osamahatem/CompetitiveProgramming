/*
 * A. Senate Evacuation.cpp
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
	freopen("out.out", "w", stdout);
#endif

	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		printf("Case #%d:", t);
		int n, sum = 0;
		scanf("%d", &n);
		priority_queue<pair<int, int>> all;
		for (int i = 0; i < n; i++) {
			int x;
			scanf("%d", &x);
			sum += x;
			all.push(make_pair(x, i));
		}
		while (all.size()) {
			pair<int, int> cur = all.top();
			all.pop();
			printf(" %c", cur.second + 'A');
			cur.first--, sum--;
			if (cur.first)
				all.push(cur);
			if (all.size() && sum != 2) {
				cur = all.top();
				all.pop();
				printf("%c", cur.second + 'A');
				cur.first--, sum--;
				if (cur.first)
					all.push(cur);
			}
		}
		printf("\n");
	}
	return 0;
}
