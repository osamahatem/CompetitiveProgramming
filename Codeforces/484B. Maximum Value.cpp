/*
 * 484B. Maximum Value.cpp
 *
 *  Created on: Mar 21, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int n, pos[1 << 20];
vector<int> arr;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	scanf("%d", &n);
	arr.resize(n);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	sort(arr.begin(), arr.end());
	arr.erase(unique(arr.begin(), arr.end()), arr.end());
	n = arr.size();
	for (int i = 1; i <= arr[n - 1]; i++)
		pos[i] = lower_bound(arr.begin(), arr.end(), i) - arr.begin();
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int val = arr[i], idx;
		do {
			val += arr[i];
			idx = val <= arr[n - 1] ? pos[val] : n;
			ans = max(ans, arr[idx - 1] % arr[i]);
		} while (val <= arr[n - 1]);
	}
	printf("%d\n", ans);
	return 0;
}
