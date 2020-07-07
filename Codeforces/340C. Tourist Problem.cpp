/*
 * 340C. Tourist Problem.cpp
 *
 *  Created on: Jan 30, 2015
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

	int n, arr[100005];
	long long sum[100005], a = 0;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	sort(arr + 1, arr + n + 1);
	for (int i = 1; i <= n; i++)
		sum[i] = arr[i] + sum[i - 1];
	for (int i = 1; i <= n; i++) {
		a += (long long) i * arr[i] - sum[i - 1];
		if (i < n)
			a += sum[n] - sum[i] - (long long) (n - i) * arr[i];
	}
	long long g = __gcd(a, (long long) n);
	a /= g, n /= g;
	cout << a << " " << n << endl;
	return 0;
}
