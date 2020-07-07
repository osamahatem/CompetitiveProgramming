/*
 * I. Larry's Quest.cpp
 *
 *  Created on: Sep 15, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1e5 + 5;

int lft[MAXN], box[MAXN];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	freopen("quest.in", "r", stdin);
	int T;
	scanf("%d", &T);
	while (T--) {
		int n, x, y;
		scanf("%d%d%d", &n, &x, &y);
		int area = x * y;
		fill(lft, lft + n, MAXN);
		for (int i = 0; i < n; i++)
			scanf("%d", &box[i]);
		if (!area) {
			printf("No\n");
			continue;
		}
		sort(box, box + n, greater<int>());
		bool ans = 1;
		for (int i = 0; i < n; i++)
			if (!lft[i % area])
				ans = 0;
			else
				lft[i % area] = min(lft[i % area] - 1, box[i]);
		printf("%s\n", ans ? "Yes" : "No");
	}
	return 0;
}
