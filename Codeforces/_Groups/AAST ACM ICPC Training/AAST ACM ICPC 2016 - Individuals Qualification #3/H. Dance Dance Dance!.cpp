/*
 * H. Dance Dance Dance!.cpp
 *
 *  Created on: Sep 1, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int arr[200005];
long long sum[200005];
map<long long, int> cnt;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

//	freopen("dance.in", "r", stdin);
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		long long ans = 0;
		cnt.clear();
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &arr[i]);
			arr[i + n] = arr[i];
		}
		sum[0] = arr[0];
		for (int i = 1; i < 2 * n; i++)
			sum[i] = sum[i - 1] + arr[i];
		if (sum[n - 1] % 6) {
			printf("0\n");
			continue;
		}
		long long x = sum[n - 1] / 6;
		for (int i = 0; i < n; i++)
			cnt[sum[i]]++;
		for (int i = 0; i < n; i++) {
			ans += 1ll * cnt[sum[i] + x - arr[i]]
					* cnt[sum[i] + x * 3 - arr[i]];
			ans += 1ll * cnt[sum[i] + x - arr[i]]
					* cnt[sum[i] + x * 4 - arr[i]];
			cnt[sum[i + n]]++;
			cnt[sum[i]]--;
		}
		printf("%lld\n", ans);
	}
	return 0;
}
