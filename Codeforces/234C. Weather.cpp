/*
 * 234C. Weather.cpp
 *
 *  Created on: Jun 17, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1e5 + 5;

int arr[MAXN];

int main() {
//#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
//#endif

	int n, before = 0, after = 0, ans = MAXN;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		if (arr[i] <= 0)
			after++;
	}
	for (int i = 0; i + 1 < n; i++) {
		if (arr[i] <= 0)
			after--;
		if (arr[i] >= 0)
			before++;
		ans = min(ans, before + after);
	}
	cout << ans << endl;
	return 0;
}
