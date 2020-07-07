/*
 * 190D. Non-Secret Cypher.cpp
 *
 *  Created on: Apr 16, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 4e5 + 5;

int arr[MAXN], sorted[MAXN];
long long dp[MAXN];
map<int, int> rnk;
vector<int> occ[MAXN];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n, k, r = 0;
	cin >> n >> k;
	int firstK = n;
	dp[n] = 0;
	for (int i = 0; i < n; i++)
		cin >> arr[i], sorted[i] = arr[i];
	sort(sorted, sorted + n);
	for (int i = 0; i < n; i++)
		if (!rnk.count(sorted[i]))
			rnk[sorted[i]] = r++;
	for (int i = 0; i < n; i++)
		arr[i] = rnk[arr[i]];
	for (int i = n - 1; i >= 0; i--) {
		occ[arr[i]].push_back(i);
		dp[i] = dp[i + 1];
		if ((int) occ[arr[i]].size() >= k) {
			int sz = (int) occ[arr[i]].size();
			int temp = n - min(occ[arr[i]][sz - k], firstK);
			dp[i] += temp;
			firstK = min(firstK, occ[arr[i]][sz - k]);
		} else if (firstK != n)
			dp[i] += n - firstK;
	}
	cout << dp[0] << endl;
	return 0;
}
