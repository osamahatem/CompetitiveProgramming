/*
 * 625C. K-special Tables.cpp
 *
 *  Created on: Mar 15, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int arr[505][505];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n, k, cnt = 1;
	long long ans = 0;
	scanf("%d%d", &n, &k);
	k--;
	for (int i = 0; i < k; i++)
		for (int j = 0; j < n; j++)
			arr[j][i] = cnt++;
	for (int i = 0; i < n; i++) {
		arr[i][k] = cnt;
		ans += cnt++;
		for (int j = k + 1; j < n; j++)
			arr[i][j] = cnt++;
	}
	printf("%lld\n", ans);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (j)
				printf(" ");
			printf("%d", arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}
