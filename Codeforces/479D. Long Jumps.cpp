/*
 * 479D. Long Jumps.cpp
 *
 *  Created on: Jun 11, 2016
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

	int n, l, x, y;
	scanf("%d%d%d%d", &n, &l, &x, &y);
	bool fx = 0, fy = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		if (binary_search(arr, arr + i + 1, arr[i] - x))
			fx = 1;
		if (binary_search(arr, arr + i + 1, arr[i] - y))
			fy = 1;
	}
	if (!fx && !fy) {
		for (int i = 0; i < n; i++) {
			if (binary_search(arr + i, arr + n, arr[i] + y - x)) {
				if (arr[i] + y < l) {
					printf("1\n%d\n", arr[i] + y);
					return 0;
				} else if (arr[i] - x > 0) {
					printf("1\n%d\n", arr[i] - x);
					return 0;
				}
			} else if (binary_search(arr + i, arr + n, arr[i] + x + y)) {
				printf("1\n%d\n", arr[i] + x);
				return 0;
			}
		}
		printf("2\n%d %d\n", x, y);
	} else if (!fx)
		printf("1\n%d\n", x);
	else if (!fy)
		printf("1\n%d\n", y);
	else
		printf("0\n");
	return 0;
}
