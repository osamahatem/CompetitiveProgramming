/*
 * D. Crazy Vacation.cpp
 *
 *  Created on: Aug 29, 2016
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

	int T;
	scanf("%d", &T);
	while (T--) {
		int n, m;
		scanf("%d%d", &n, &m);
		string ans = "";
		char name[30];
		int x, d = -300, mxx = -101;
		while (n--) {
			scanf("%s", name);
			int mn = 100, mx = -100;
			for (int i = 0; i < m; i++) {
				scanf("%d", &x);
				mx = max(mx, x);
			}
			for (int i = 0; i < m; i++) {
				scanf("%d", &x);
				mn = min(mn, x);
			}
			if (abs(mx - mn) > d || (abs(mx - mn) == d && mx > mxx))
				ans = name, mxx = mx, d = abs(mx - mn);
		}
		printf("%s\n", ans.c_str());
	}
	return 0;
}
