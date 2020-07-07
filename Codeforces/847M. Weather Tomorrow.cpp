/*
 * 847M. Weather Tomorrow.cpp
 *
 *  Created on: Sep 27, 2017
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

	int n, last, cur, diff, ans;
	bool flag = 1;
	scanf("%d%d%d", &n, &last, &cur);
	diff = cur - last;
	last = cur;
	for (int i = 2; i < n; i++) {
		scanf("%d", &cur);
		if (cur - last != diff)
			flag = 0;
		last = cur;
	}
	if (flag)
		ans = last + diff;
	else
		ans = last;
	printf("%d\n", ans);
	return 0;
}
