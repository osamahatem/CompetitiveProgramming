/*
 * 6896 - Eureka Theorem.cpp
 *
 *  Created on: Oct 2, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int arr[100];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	for (int i = 1; i < 100; i++)
		arr[i] = i * (i + 1) / 2;
	int T;
	scanf("%d", &T);
	while (T--) {
		int k;
		int ans = 0;
		scanf("%d", &k);
		for (int i = 1; arr[i] <= k; i++)
			for (int j = i; arr[i] + arr[j] <= k; j++)
				for (int kk = j; arr[i] + arr[j] + arr[kk] <= k; kk++)
					if (arr[i] + arr[j] + arr[kk] == k)
						ans = 1;
		printf("%d\n", ans);
	}
	return 0;
}
