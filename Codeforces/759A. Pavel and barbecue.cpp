/*
 * 759A. Pavel and barbecue.cpp
 *
 *  Created on: Jan 22, 2017
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 2e5 + 5;

int arr[MAXN];
bool vis[MAXN];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n, x, ans = 1;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &arr[i]);
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		ans ^= x;
	}
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (vis[i])
			continue;
		int x = i;
		while (!vis[x]) {
			vis[x] = 1;
			x = arr[x];
		}
		cnt++;
	}
	ans += cnt == 1 ? 0 : cnt;
	printf("%d\n", ans);
	return 0;
}
