/*
 * 558C. Amr and Chemistry.cpp
 *
 *  Created on: Jul 14, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1e5 + 5;

int arr[MAXN], cnt[MAXN], steps[MAXN], vis[MAXN];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n, ans = 1 << 30, id = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		id++;
		for (int s1 = 0; arr[i]; s1++, arr[i] /= 2)
			for (int s2 = 0, temp = arr[i]; temp < MAXN; s2++, temp *= 2)
				if (vis[temp] != id)
					cnt[temp]++, steps[temp] += s1 + s2, vis[temp] = id;
	}
	for (int i = 1; i < MAXN; i++)
		if (cnt[i] == n && steps[i] < ans)
			ans = steps[i];
	cout << ans << endl;
	return 0;
}
