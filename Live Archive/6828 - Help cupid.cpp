/*
 * 6828 - Help cupid.cpp
 *
 *  Created on: Sep 21, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int N, arr[1005];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	while (scanf("%d", &N) != EOF) {
		for (int i = 0; i < N; i++)
			scanf("%d", &arr[i]);
		sort(arr, arr + N);
		int ans = 0;
		for (int i = 1; i < N; i += 2)
			ans += min(arr[i] - arr[i - 1], 24 - arr[i] + arr[i - 1]);
		int temp = min(arr[N - 1] - arr[0], 24 - arr[N - 1] + arr[0]);
		for (int i = 2; i < N; i += 2)
			temp += min(arr[i] - arr[i - 1], 24 - arr[i] + arr[i - 1]);
		ans = min(ans, temp);
		printf("%d\n", ans);
	}
	return 0;
}
