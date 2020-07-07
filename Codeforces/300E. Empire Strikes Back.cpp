/*
 * 300E. Empire Strikes Back.cpp
 *
 *  Created on: Jul 23, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXV = 1e7 + 5;
const int MAXK = 1e6 + 5;

int k, factor[MAXV], arr[MAXK];
long long cnt[MAXV];

void init() {
	memset(factor, -1, sizeof factor);
	for (int i = 2; i <= arr[k - 1]; i++) {
		if (factor[i] == -1)
			for (int j = i; j <= arr[k - 1]; j += i)
				factor[j] = i;
	}
}

long long cntFactor(long long x, long long f) {
	long long ret = 0;
	while (x >= f) {
		ret += x / f;
		x /= f;
	}
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	scanf("%d", &k);
	for (int i = 0; i < k; i++)
		scanf("%d", &arr[i]);
	sort(arr, arr + k);
	init();
	for (int idx = 0, i = 2; i <= arr[k - 1]; i++) {
		while (arr[idx] < i)
			idx++;
		int x = i;
		while (x > 1) {
			cnt[factor[x]] += k - idx;
			x /= factor[x];
		}
	}
	long long ans = 1;
	for (int i = 2; i <= arr[k - 1]; i++) {
		long long s = 1, e = cnt[i];
		while (s < e) {
			long long mid = (s + e) / 2;
			if (cntFactor(mid, i) + mid < cnt[i])
				s = mid + 1;
			else
				e = mid;
		}
		ans = max(ans, s * i);
	}
	printf("%lld\n", ans);
	return 0;
}
