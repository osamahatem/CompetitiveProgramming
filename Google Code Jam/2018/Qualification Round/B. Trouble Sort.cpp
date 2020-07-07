/*
 * B. Trouble Sort.cpp
 *
 *  Created on: Apr 7, 2018
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1e5 + 5;

int T, n, arr[MAXN];
vector<int> even, odd;

int main() {
//#ifndef ONLINE_JUDGE
//	freopen("in.in", "r", stdin);
////	freopen("out.out", "w", stdout);
//#endif

	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> T;
	for (int t = 1; t <= T; t++) {
		odd.clear(), even.clear();

		cin >> n;
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			(i & 1 ? odd : even).push_back(x);
		}
		sort(odd.begin(), odd.end()), sort(even.begin(), even.end());

		for (int i = n - 1; ~i; i--) {
			arr[i] = (i & 1 ? odd : even).back();
			(i & 1 ? odd : even).pop_back();
		}

		int ans = n;
		for (int i = n - 2; ~i; i--)
			if (arr[i] > arr[i + 1])
				ans = i;
		cout << "Case #" << t << ": ";
		if (ans == n)
			cout << "OK" << endl;
		else
			cout << ans << endl;
	}
	return 0;
}
