/*
 * 286C. Main Sequence.cpp
 *
 *  Created on: Sep 16, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int n, k, arr[1000000], sum;
bool closed[1000000];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	scanf("%d", &k);
	while (k--) {
		int x;
		scanf("%d", &x);
		closed[--x] = 1;
	}
	stack<int> S;
	for (int i = n - 1; i >= 0; i--) {
		if (!closed[i] && sum && S.top() == arr[i]) {
			sum--;
			S.pop();
		} else {
			S.push(arr[i]);
			sum++;
			arr[i] *= -1;
		}
	}
	printf("%s\n", sum ? "NO" : "YES");
	if (!sum) {
		for (int i = 0; i < n; i++) {
			if (i)
				printf(" ");
			printf("%d", arr[i]);
		}
	}
	printf("\n");
	return 0;
}
