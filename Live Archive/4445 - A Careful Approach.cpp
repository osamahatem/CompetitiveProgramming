/*
 * 4445 - A Careful Approach.cpp
 *
 *  Created on: Feb 1, 2018
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const double EPS = 1e-9;

int n;
pair<double, double> arr[10];

bool check(double t) {
	sort(arr, arr + n);
	bool ret = false;
	do {
		double x = arr[0].first;
		bool flag = true;
		for (int i = 1; flag && i < n; i++) {
			x = max(x + t, arr[i].first);
			if (x > arr[i].second + EPS)
				flag = false;
		}
		ret |= flag;
	} while (!ret && next_permutation(arr, arr + n));
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int T = 0;
	while (cin >> n, n) {
		for (int i = 0; i < n; i++) {
			cin >> arr[i].first >> arr[i].second;
			arr[i].first *= 60.0;
			arr[i].second *= 60.0;
		}
		double s = 0.0;
		for (double sz = 1e5; sz > EPS; sz /= 2.0) {
			if (check(s + sz))
				s += sz;
		}
		int ans = (int) (s + 0.5 + EPS);
		cout << "Case " << ++T << ": " << ans / 60 << ":";
		cout << setfill('0') << setw(2) << ans % 60 << endl;
	}
	return 0;
}
