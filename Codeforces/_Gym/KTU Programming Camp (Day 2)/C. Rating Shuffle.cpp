/*
 * C. Rating Shuffle.cpp
 *
 *  Created on: May 13, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int n, d, arr[100005];

long long getHighest(long long prv, long long cur, long long steps) {
	cur += steps * d;
	if (cur < prv)
		return cur;
	long long diff = (cur - prv) / (d << 1) + 1;
	if (diff > steps)
		return prv;
	cur -= diff * (d << 1);
	return cur;
}

bool check(long long x) {
	long long prv = x * d + arr[0];
	for (int i = 1; i < n; i++) {
		long long cur = getHighest(prv, arr[i], x);
		if (cur >= prv)
			return false;
		prv = cur;
	}
	return true;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	scanf("%d%d", &n, &d);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	long long s = 0, e = 2e9 + 1;
	while (s < e) {
		long long mid = (s + e) / 2;
		if (check(mid))
			e = mid;
		else
			s = mid + 1;
	}
	printf("%lld\n", s);
	return 0;
}
