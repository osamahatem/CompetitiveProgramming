/*
 * 722D. Generating Sets.cpp
 *
 *  Created on: Oct 1, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int n, arr[50005], ans[50005];

bool check(int x) {
	set<int> used;
	for (int i = 0; i < n; i++) {
		int xx = arr[i];
		ans[i] = -1;
		while (xx) {
			if (xx <= x && !used.count(xx)) {
				ans[i] = xx, used.insert(xx);
				break;
			}
			xx /= 2;
		}
		if (ans[i] == -1)
			return false;
	}
	return true;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	int s = 1, e = *max_element(arr, arr + n);
	while (s < e) {
		int mid = (s + e) / 2;
		if (check(mid))
			e = mid;
		else
			s = mid + 1;
	}
	check(s);
	for (int i = 0; i < n; i++) {
		if (i)
			printf(" ");
		printf("%d", ans[i]);
	}
	printf("\n");
	return 0;
}
