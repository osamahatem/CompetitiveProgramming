/*
 * 279C. Ladder.cpp
 *
 *  Created on: May 17, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1e5 + 5;

int arr[MAXN];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	int st = 0, idx = 1, last = 0, l, r;
	vector<pair<int, int> > intervals;
	while (idx < n) {
		while (idx < n && arr[idx] >= arr[idx - 1]) {
			if (arr[idx] != arr[idx - 1])
				last = idx;
			idx++;
		}
		while (idx < n && arr[idx] <= arr[idx - 1]) {
			if (arr[idx] != arr[idx - 1])
				last = idx;
			idx++;
		}
		intervals.push_back(make_pair(st, idx - 1));
		st = last;
	}
	if (intervals.empty())
		intervals.push_back(make_pair(0, 0));
	for (int i = 0; i < m; i++) {
		cin >> l >> r;
		l--, r--;
		pair<int, int> val = make_pair(l, n);
		int id = upper_bound(intervals.begin(), intervals.end(), val)
				- intervals.begin() - 1;
		if (intervals[id].second < r)
			cout << "No" << endl;
		else
			cout << "Yes" << endl;
	}
	return 0;
}
