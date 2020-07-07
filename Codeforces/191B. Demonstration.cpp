/*
 * 191B. Demonstration.cpp
 *
 *  Created on: Oct 14, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1e5 + 5;

vector<pair<int, int>> all;
int n, k, pos[MAXN];
long long tot;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	scanf("%d%d%lld", &n, &k, &tot);
	all.resize(n - 1), k--;
	for (int i = 0; i + 1 < n; i++)
		scanf("%d", &all[i].first), all[i].second = i;
	sort(all.begin(), all.end(), greater<pair<int, int>>());
	for (int i = 0; i + 1 < n; i++)
		pos[all[i].second] = i;
	long long sum = 0;
	for (int i = 0; i < k; i++)
		sum += all[i].first;
	int ans = n;
	for (int i = 0; i + 1 < n; i++) {
		long long temp = sum;
		if (pos[i] < k)
			temp += all[k].first - all[pos[i]].first;
		if (temp + all[pos[i]].first > tot) {
			ans = i + 1;
			break;
		}
	}
	printf("%d\n", ans);
	return 0;
}
