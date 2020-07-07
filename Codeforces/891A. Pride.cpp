/*
 * 891A. Pride.cpp
 *
 *  Created on: Nov 17, 2017
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int n, arr[2005];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int mini = -1, ans = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		int g = arr[i];
		ans += arr[i] != 1;
		for (int j = i; ~j; j--) {
			g = __gcd(g, arr[j]);
			if (g == 1) {
				mini = mini == -1 ? i - j : min(mini, i - j);
				break;
			}
		}
	}
	ans = mini == -1 ? -1 : ans + mini;
	if (mini > 0)
		ans--;
	printf("%d\n", ans);
	return 0;
}
