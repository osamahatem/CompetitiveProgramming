/*
 * 354C. Vasya and Beautiful Arrays.cpp
 *
 *  Created on: Jul 13, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXA = 2e6 + 5;
const int MAXN = 3e5 + 5;

int arr[MAXN], cnt[MAXA];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n, k, mini = 1 << 20, maxi = 0;
//	cin >> n >> k;
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++) {
//		cin >> arr[i];
		scanf("%d", &arr[i]);
		mini = min(mini, arr[i]), maxi = max(maxi, arr[i]);
		cnt[arr[i]]++;
	}
	if (mini <= k + 1) {
//		cout << mini << endl;
		printf("%d\n", mini);
		return 0;
	}
	for (int i = 0; i < MAXA; i++)
		cnt[i] += cnt[i - 1];
	for (; mini > k; mini--) {
		int curCnt = 0;
		for (int i = 1; i <= maxi / mini; i++)
			curCnt += cnt[i * mini + k] - cnt[i * mini - 1];
		if (curCnt == n) {
//			cout << mini << endl;
			printf("%d\n", mini);
			return 0;
		}
	}
	return 0;
}
