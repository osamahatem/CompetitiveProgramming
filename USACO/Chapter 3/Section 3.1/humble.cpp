/*
 ID: 19semse1
 PROG: humble
 LANG: C++
 */
/*
 * humble.cpp
 *
 *  Created on: Mar 16, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int main() {
//#ifndef ONLINE_JUDGE
	freopen("humble.in", "r", stdin);
	freopen("humble.out", "w", stdout);
//#endif

	int k, n, arr[105], ans;
	set<int> all;
	cin >> k >> n;
	for (int i = 0; i < k; i++)
		cin >> arr[i], all.insert(arr[i]);
	while (n--) {
		ans = *all.begin();
		all.erase(all.begin());
		for (int i = 0; i < k; i++)
			if (LONG_MAX / arr[i] >= ans
					&& ((int) all.size() <= n || ans * arr[i] < *(--all.end())))
				all.insert(ans * arr[i]);
		while ((int) all.size() > n)
			all.erase(--all.end());
	}
	cout << ans << endl;
	return 0;
}
