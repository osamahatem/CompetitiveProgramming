/*
 * H. subsum.cpp
 *
 *  Created on: Sep 7, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int arr[100005];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	freopen("subsum.in", "r", stdin);
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		int n, q, a, b;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%d", &arr[i]);
			arr[i] += arr[i - 1];
		}
		printf("Case %d:\n", t);
		scanf("%d", &q);
		while (q--) {
			scanf("%d%d", &a, &b);
			printf("%d\n", arr[b] - arr[a - 1]);
		}
	}
	return 0;
}
