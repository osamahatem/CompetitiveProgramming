/*
 * 363D. Renting Bikes.cpp
 *
 *  Created on: Aug 25, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1e5 + 5;

int n, m, a, money[MAXN], bike[MAXN];

int check(int cnt) {
	int spent = 0, needed = 0;
	for (int i = 0, cm = n - cnt; i < cnt; i++, cm++) {
		spent += min(bike[i], money[cm]);
		needed += max(0, bike[i] - money[cm]);
		if (needed > a)
			return -1;
	}
	return max(0, spent - (a - needed));
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	scanf("%d%d%d", &n, &m, &a);
	for (int i = 0; i < n; i++)
		scanf("%d", &money[i]);
	for (int i = 0; i < m; i++)
		scanf("%d", &bike[i]);
	sort(money, money + n);
	sort(bike, bike + m);
	int s = 0, e = min(n, m);
	while (s < e) {
		int mid = (s + e + 1) / 2;
		if (check(mid) != -1)
			s = mid;
		else
			e = mid - 1;
	}
	printf("%d %d\n", s, check(s));
	return 0;
}
