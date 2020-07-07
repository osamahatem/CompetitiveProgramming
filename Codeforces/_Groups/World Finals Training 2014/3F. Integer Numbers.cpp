/*
 * 3F. Integer Numbers.cpp
 *
 *  Created on: Feb 9, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 5e4 + 5;

int main() {
//#ifndef ONLINE_JUDGE
	freopen("integer.in", "r", stdin);
	freopen("integer.out", "w", stdout);
//#endif

	int n, arr[MAXN], maxLen = 0, maxStart;
	map<int, int> cnt;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	for (int i = 0; i < n; i++) {
		cnt[arr[i] - i]++;
		if (cnt[arr[i] - i] > maxLen)
			maxLen = cnt[arr[i] - i], maxStart = arr[i] - i;
	}
	cout << n - maxLen << endl;
	for (int i = 0; i < n; i++, maxStart++) {
		if (i)
			cout << " ";
		cout << maxStart;
	}
	cout << endl;
	return 0;
}
