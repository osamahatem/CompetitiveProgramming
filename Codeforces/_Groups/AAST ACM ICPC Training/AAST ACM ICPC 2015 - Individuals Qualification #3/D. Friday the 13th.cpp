/*
 * D. Friday the 13th.cpp
 *
 *  Created on: Sep 10, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int dpm[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

struct date {
	int d, m, y;

	bool isLeap() {
		return (y % 4 == 0 && (y % 100 || y % 400 == 0));
	}

	const bool operator <(const date &a) const {
		if (y != a.y)
			return y < a.y;
		if (m != a.m)
			return m < a.m;
		return d < a.d;
	}

	const void operator ++() {
		d++;
		if (d > dpm[m - 1] && !(isLeap() && d == 29 && m == 2))
			m++, d = 1;
		if (m == 13)
			y++, m = 1;
	}
};

int dist(date d1, date d2) {
	if (d2 < d1)
		swap(d1, d2);
	int ret = 0;
	while (d1 < d2)
		++d1, ret++;
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	freopen("friday.in", "r", stdin);
	int T;
	scanf("%d", &T);
	date friday { 13, 6, 2014 }, d1 { 1, 1, 1970 }, d2 { 1, 1, 2051 };
	vector<date> valid;
	while (d1 < d2) {
		if (d1.d == 13 && dist(d1, friday) % 7 == 0)
			valid.push_back(d1);
		++d1;
	}
	for (int t = 1; t <= T; t++) {
		scanf("%d%*c%d%*c%d%*c%*c%*c%d%*c%d%*c%d", &d1.d, &d1.m, &d1.y, &d2.d,
				&d2.m, &d2.y);
		int a = lower_bound(valid.begin(), valid.end(), d1) - valid.begin();
		int b = upper_bound(valid.begin(), valid.end(), d2) - valid.begin();
		int ans = b - a;
		if (ans)
			printf(
					"Friday the 13th occurs %d time(s) throughout Loubna's career.\n",
					ans);
		else
			printf(
					"Loubna is so unlucky, Friday the 13th doesn't occur throughout her career.\n");
	}
	return 0;
}
