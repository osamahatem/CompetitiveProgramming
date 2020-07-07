/*
 * 450B. Jzzhu and Sequences.cpp
 *
 *  Created on: Jul 3, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	long long arr[6];
	cin >> arr[0] >> arr[1];
	for (int i = 2; i < 6; i++)
		arr[i] = arr[i - 1] - arr[i - 2];
	int n;
	cin >> n;
	n--;
	n %= 6;
	long long ans = arr[n] % 1000000007;
	if (ans < 0)
		ans += 1000000007;
	cout << ans << endl;
	return 0;
}
