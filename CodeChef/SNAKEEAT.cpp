/*
 * SNAKEEAT.cpp
 *
 *  Created on: May 20, 2017
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1e5 + 5;

int N, Q, arr[MAXN];
long long sum[MAXN];

int solve(int k) {
	int s = 0, e = N;
	while (s < e) {
		int mid = (s + e) / 2;
		if (arr[mid] < k)
			s = mid + 1;
		else
			e = mid;
	}
	int E = s;
	s = 0, e = E;
	while (s < e) {
		int mid = (s + e) / 2;
		int len = E - mid;
		long long need = 1ll * k * len - sum[E - 1] + (mid ? sum[mid - 1] : 0);
		if (need > mid)
			s = mid + 1;
		else
			e = mid;
	}
	return N - s;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &N, &Q);
		for (int i = 0; i < N; i++)
			scanf("%d", &arr[i]);
		sort(arr, arr + N);
		arr[N] = 1e9 + 5;
		sum[0] = arr[0];
		for (int i = 1; i <= N; i++)
			sum[i] = sum[i - 1] + arr[i];
		while (Q--) {
			int k;
			scanf("%d", &k);
			printf("%d\n", solve(k));
		}
	}
	return 0;
}
