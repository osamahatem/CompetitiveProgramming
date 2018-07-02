/*
 * 359D. Pair of Numbers.cpp
 *
 *  Created on: Jul 2, 2018
 *      Author: Osama Hatem
 */

/*
 * http://codeforces.com/blog/entry/9425
 *
 * The following solution is slightly different from the above editorial:
 * Use sparse tables to store cumulative GCDs before and after each element.
 * Then, for each element, use those two tables to get the biggest sub-array for
 * which the GCD is divisible by the element, and update the answer accordingly.
 * Time Complexity: O(N * log(N))
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 3e5 + 5;
const int LOGN = 19;

int n, arr[MAXN], gcd_before[MAXN][LOGN], gcd_after[MAXN][LOGN];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		gcd_before[i][0] = gcd_after[i][0] = arr[i];
	}

	for (int j = 1; j < LOGN; j++) {
		for (int i = 0; i < n; i++) {
			if (i - (1 << j) + 1 >= 0)
				gcd_before[i][j] = __gcd(gcd_before[i][j - 1],
						gcd_before[i - (1 << (j - 1))][j - 1]);
			if (i + (1 << j) - 1 < n)
				gcd_after[i][j] = __gcd(gcd_after[i][j - 1],
						gcd_after[i + (1 << (j - 1))][j - 1]);
		}
	}

	int len = -1;
	vector<int> ans;
	for (int i = 0; i < n; i++) {
		int l = i, r = i;
		for (int j = LOGN - 1; ~j; j--)
			if (l - (1 << j) + 1 >= 0 && gcd_before[l][j] % arr[i] == 0)
				l -= 1 << j;
		for (int j = LOGN - 1; ~j; j--)
			if (r + (1 << j) - 1 < n && gcd_after[r][j] % arr[i] == 0)
				r += 1 << j;
		l += 2;
		if (r - l > len)
			len = r - l, ans.clear();
		if (r - l == len && (ans.empty() || l != ans.back()))
			ans.push_back(l);
	}

	cout << ans.size() << " " << len << endl;
	for (int i = 0; i < (int) ans.size(); i++) {
		if (i)
			cout << " ";
		cout << ans[i];
	}
	cout << endl;
	return 0;
}
