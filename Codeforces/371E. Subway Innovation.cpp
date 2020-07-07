/*
 * 371E. Subway Innovation.cpp
 *
 *  Created on: Jul 21, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int n, k;
pair<int, int> arr[300005];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i].first), arr[i].second = i + 1;
	scanf("%d", &k);
	sort(arr, arr + n);
	deque<int> Q;
	long long mini = 1ll << 62, sum = 0, cur = 0;
	int idx = 0;
	for (int i = 0; i < n; i++) {
		Q.push_back(arr[i].first);
		sum += arr[i].first;
		int sz = Q.size();
		cur += 1ll * sz * arr[i].first - sum;
		if (sz > k) {
			int rem = Q.front();
			Q.pop_front();
			cur -= sum - 1ll * sz * rem;
			sum -= rem;
		}
		if (sz >= k && cur < mini)
			mini = cur, idx = i;
	}
	idx -= k - 1;
	for (int i = 0; i < k; i++) {
		if (i)
			printf(" ");
		printf("%d", arr[idx++].second);
	}
	printf("\n");
	return 0;
}
