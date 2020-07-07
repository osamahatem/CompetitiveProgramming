/*
 * 489E. LIS of Sequence.cpp
 *
 *  Created on: Jun 24, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1e5 + 5;

int N, arr[MAXN], end_here[MAXN], start_here[MAXN], cnt[MAXN], ans[MAXN], lis;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	vector<int> temp;
	for (int i = 0; i < N; i++) {
		int idx = lower_bound(temp.begin(), temp.end(), arr[i]) - temp.begin();
		if (idx == (int) temp.size())
			temp.push_back(arr[i]);
		else
			temp[idx] = arr[i];
		end_here[i] = idx + 1;
		cnt[end_here[i]]++;
		lis = max(lis, end_here[i]);
	}
	temp.clear();
	for (int i = N - 1; i >= 0; i--) {
		int idx = lower_bound(temp.begin(), temp.end(), arr[i], greater<int>())
				- temp.begin();
		if (idx == (int) temp.size())
			temp.push_back(arr[i]);
		else
			temp[idx] = arr[i];
		start_here[i] = idx + 1;
		if (end_here[i] + start_here[i] - 1 < lis)
			cnt[end_here[i]]--;
	}
	for (int i = 0; i < N; i++) {
		if (end_here[i] + start_here[i] - 1 < lis)
			ans[i] = 1;
		else if (cnt[end_here[i]] == 1)
			ans[i] = 3;
		else
			ans[i] = 2;
	}
	for (int i = 0; i < N; i++)
		cout << ans[i];
	cout << endl;
	return 0;
}
