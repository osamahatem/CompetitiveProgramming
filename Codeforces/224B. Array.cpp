/*
 * 224B. Array.cpp
 *
 *  Created on: Apr 17, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1e5 + 5;

int arr[MAXN];
map<int, int> cnt;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n, k, s = 0, e;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	for (int i = 0; i < n && k; i++) {
		cnt[arr[i]]++;
		if (cnt[arr[i]] == 1)
			k--;
		e = i;
	}
	if (k) {
		cout << "-1 -1" << endl;
		return 0;
	}
	for (int i = 0; i < n && cnt[arr[i]] > 1; i++) {
		s = i + 1;
		cnt[arr[i]]--;
	}
	cout << ++s << " " << ++e << endl;
	return 0;
}
