/*
 * 724B. Batch Sort.cpp
 *
 *  Created on: Feb 8, 2017
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int n, m, mat[22][22];

bool canOneSwap(int arr[]) {
	for (int i = 0; i < m; i++) {
		int j = arr[i];
		if (arr[j] == i && i != j) {
			swap(arr[i], arr[j]);
			bool ret = is_sorted(arr, arr + m);
			swap(arr[i], arr[j]);
			return ret;
		}
	}
	return is_sorted(arr, arr + m);
}

bool check() {
	bool ans = true;
	for (int i = 0; i < n; i++)
		ans &= canOneSwap(mat[i]);
	return ans;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			cin >> mat[i][j];
			mat[i][j]--;
		}
	bool ans = check();
	for (int i = 0; i < m; i++) {
		for (int j = i + 1; j < m; j++) {
			for (int k = 0; k < n; k++)
				swap(mat[k][i], mat[k][j]);
			ans |= check();
			for (int k = 0; k < n; k++)
				swap(mat[k][i], mat[k][j]);
		}
	}
	cout << (ans ? "YES" : "NO") << endl;
	return 0;
}
