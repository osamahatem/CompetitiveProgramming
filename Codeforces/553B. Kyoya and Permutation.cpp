/*
 * 553B. Kyoya and Permutation.cpp
 *
 *  Created on: Jun 24, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int N, arr[55];
long long cnt[55];

void solve(long long k) {
	for (int i = 0; i < N; i++) {
		if (i + 1 < N && k > cnt[N - i - 1]) {
			k -= cnt[N - i - 1];
			swap(arr[i], arr[i + 1]);
			i++;
		}
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	cnt[1] = 1, cnt[2] = 2;
	long long k;
	cin >> N >> k;
	for (int i = 3; i <= N; i++)
		cnt[i] = cnt[i - 1] + cnt[i - 2];
	for (int i = 0; i < N; i++)
		arr[i] = i + 1;
	solve(k);
	for (int i = 0; i < N; i++) {
		if (i)
			cout << " ";
		cout << arr[i];
	}
	cout << endl;
	return 0;
}
