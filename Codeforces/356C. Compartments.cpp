/*
 * 356C. Compartments.cpp
 *
 *  Created on: Aug 23, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int n, x, ans, cnt[5];

void NO() {
	printf("-1\n");
	exit(0);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	scanf("%d", &n);
	while (n--) {
		scanf("%d", &x);
		cnt[x]++;
	}
	x = min(cnt[1], cnt[2]);
	ans += x, cnt[1] -= x, cnt[2] -= x, cnt[3] += x;
	x = cnt[1];
	ans += x / 3 * 2, cnt[3] += x / 3, cnt[1] %= 3;
	x = cnt[2];
	ans += x / 3 * 2, cnt[3] += x / 3 * 2, cnt[2] %= 3;
	if (cnt[2] == 2) {
		ans += 2;
	} else if (cnt[2] == 1) {
		if (cnt[4])
			ans++;
		else if (cnt[3] >= 2)
			ans += 2;
		else
			NO();
	} else if (cnt[1] == 1) {
		if (cnt[3])
			ans++;
		else if (cnt[4] >= 2)
			ans += 2;
		else
			NO();
	} else if (cnt[1] == 2) {
		if (cnt[4] || cnt[3] >= 2)
			ans += 2;
		else
			NO();
	}
	printf("%d\n", ans);
	return 0;
}
