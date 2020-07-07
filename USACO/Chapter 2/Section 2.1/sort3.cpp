/*
 ID: 19semse1
 PROG: sort3
 LANG: C++
 */
/*
 * sort3.cpp
 *
 *  Created on: Mar 7, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int main() {
//#ifndef ONLINE_JUDGE
	freopen("sort3.in", "r", stdin);
	freopen("sort3.out", "w", stdout);
//#endif

	int n, arr[1005], arr2[1005];
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i], arr2[i] = arr[i];
	sort(arr2, arr2 + n);
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] == arr2[i])
			continue;
		ans++;
		bool flag = 0;
		for (int j = i + 1; j < n; j++) {
			if (arr[j] == arr2[j])
				continue;
			if (arr[i] != arr[j] && arr[i] == arr2[j] && arr[j] == arr2[i]) {
				flag = 1;
				swap(arr[i], arr[j]);
				break;
			}
		}
		if (flag)
			continue;
		for (int j = i + 1; j < n; j++) {
			if (arr[j] == arr2[j])
				continue;
			if (arr[i] != arr[j] && arr[j] == arr2[i]) {
				swap(arr[i], arr[j]);
				break;
			}
		}
	}
	cout << ans << endl;
	return 0;
}
