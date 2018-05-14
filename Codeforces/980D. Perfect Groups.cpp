/*
 * 980D. Perfect Groups.cpp
 *
 *  Created on: May 8, 2018
 *      Author: Osama Hatem
 */

/*
 * http://codeforces.com/blog/entry/59350
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 5e3 + 5;
const int MAXV = 1e4 + 5;

int n, arr[MAXN], ans[MAXN];
vector<int> pr, rnk;
bool vis[MAXV];

void init() {
	for (int i = 2; i < MAXV; i++) {
		if (!vis[i]) {
			pr.push_back(i);
			for (int j = i * i; j < MAXV; j += i)
				vis[j] = 1;
		}
	}
}

int prep(int x) {
	if (x == 0)
		return x;

	for (int i = 0; i < (int) pr.size() && pr[i] * pr[i] <= abs(x); i++) {
		int cnt = 0;
		while (x % pr[i] == 0)
			x /= pr[i], cnt ^= 1;
		if (cnt)
			x *= pr[i];
	}
	return x;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	init();

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		arr[i] = prep(arr[i]);
		rnk.push_back(arr[i]);
	}

	sort(rnk.begin(), rnk.end());
	rnk.erase(unique(rnk.begin(), rnk.end()), rnk.end());
	for (int i = 0; i < n; i++)
		arr[i] = lower_bound(rnk.begin(), rnk.end(), arr[i]) - rnk.begin();

	memset(vis, 0, sizeof vis);
	for (int i = 0; i < n; i++) {
		bool zero = false;
		int temp = 0;
		for (int j = i; j < n; j++) {
			if (rnk[arr[j]] == 0)
				zero = true;
			else if (!vis[arr[j]])
				temp++;
			vis[arr[j]] = true;
			ans[temp + (zero && temp == 0)]++;
		}

		for (int j = i; j < n; j++)
			vis[arr[j]] = false;
	}

	for (int i = 1; i <= n; i++)
		cout << ans[i] << " \n"[i == n];
	return 0;
}
