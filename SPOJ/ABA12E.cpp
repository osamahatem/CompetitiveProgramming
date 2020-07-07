/*
 * ABA12E.cpp
 *
 *  Created on: Jun 17, 2017
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 5e4 + 5;

int n, arr[MAXN];
long long k;

long long check(long long lim) {
	int idx = 0;
	long long sum = 0, cnt = 0;
	for (int i = 0; i < n; i++) {
		while (idx < i)
			idx++;
		while (idx < n && sum + arr[idx] <= lim)
			sum += arr[idx++];
		cnt += idx - i;
		if (idx > i)
			sum -= arr[i];
	}
	return cnt;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	while (scanf("%d%lld", &n, &k) == 2) {
		for (int i = 0; i < n; i++)
			scanf("%d", &arr[i]);
		long long s = 0, e = 1e14;
		while (s < e) {
			long long mid = (s + e) / 2;
			if (check(mid) >= k)
				e = mid;
			else
				s = mid + 1;
		}
		printf("%lld\n", s);
	}
	return 0;
}
