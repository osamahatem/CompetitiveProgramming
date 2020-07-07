/*
 * 488B. Candy Boxes.cpp
 *
 *  Created on: Nov 21, 2014
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

bool check(int ar[]) {
	int arr[4] = { ar[0], ar[1], ar[2], ar[3] };
	sort(arr, arr + 4);
	int range = arr[3] - arr[0];
	if ((arr[0] + arr[1] + arr[2] + arr[3]) % 4)
		return false;
	int avg = (arr[0] + arr[1] + arr[2] + arr[3]) / 4;
	if ((arr[1] + arr[2]) % 2)
		return false;
	int med = (arr[1] + arr[2]) / 2;
	return (range == avg && range == med);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n, arr[4];
	cin >> n;
	if (n == 0) {
		cout << "YES\n1\n1\n3\n3\n";
		return 0;
	}
	if (n == 1) {
		cout << "YES\n";
		cin >> arr[1];
		if (arr[1] % 2)
			arr[2] = arr[1] + 2;
		else
			arr[2] = arr[1];
		int avg = (arr[1] + arr[2]) / 2;
		avg -= arr[2] - arr[1];
		arr[3] = arr[2] + avg / 2;
		arr[0] = arr[1] - avg / 2;
		cout << arr[0] << "\n" << arr[2] << "\n" << arr[3] << endl;
		return 0;
	}
	if (n == 4) {
		cin >> arr[0] >> arr[1] >> arr[2] >> arr[3];
		cout << (check(arr) ? "YES\n" : "NO\n");
		return 0;
	}
	if (n == 3) {
		cin >> arr[0] >> arr[1] >> arr[2];
		for (int i = 1; i <= 1000000; i++) {
			arr[3] = i;
			if (check(arr)) {
				cout << "YES\n" << arr[3] << endl;
				return 0;
			}
		}
		cout << "NO\n";
		return 0;
	}
	cin >> arr[0] >> arr[1];
	int max1 = max(arr[0], arr[1]);
	int min1 = min(arr[0], arr[1]);
	for (int i = 1; i <= 1000000; i++) {
		arr[3] = i;
		int max2 = max(max1, arr[3]);
		int min2 = min(min1, arr[3]);
		int range = max2 - min2;
		arr[2] = 4 * range - arr[0] - arr[1] - arr[3];
		if (check(arr)) {
			cout << "YES\n" << arr[2] << "\n" << arr[3] << endl;
			return 0;
		}
	}
	cout << "NO\n";
	return 0;
}
