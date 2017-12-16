/*
 * 898D. Alarm Clock.cpp
 *
 *  Created on: Dec 16, 2017
 *      Author: Osama Hatem
 */
 
/*
Iterate over elements in order. Only turn off alarms when they violate the
conditions, following a greedy strategy.
*/

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int n, m, k;
	cin >> n >> m >> k;
	vector<int> arr(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr.begin(), arr.end());
	int ans = 0;
	set<int> S;
	for (int i = 0; i < n; i++) {
		while (!S.empty() && *S.begin() < arr[i] - m + 1)
			S.erase(S.begin());
		if ((int) S.size() < k - 1)
			S.insert(arr[i]);
		else
			ans++;
	}
	cout << ans << endl;
	return 0;
}
