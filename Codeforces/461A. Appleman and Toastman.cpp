/*
 * 461A. Appleman and Toastman.cpp
 *
 *  Created on: Aug 26, 2014
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 3e5 + 5;
int arr[MAXN];
long long sum[MAXN];

long long solve(int s, int e) {
	if (s == e)
		return arr[s];
	long long ret = sum[e] - sum[s - 1];
	ret += solve(s, s) + solve(s + 1, e);
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n;
	cin >> n;
	sum[0] = 0;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	sort(arr + 1, arr + 1 + n);
	for (int i = 1; i <= n; i++)
		sum[i] = sum[i - 1] + arr[i];
	cout << solve(1, n) << "\n";
	return 0;
}
