/*
 * 879D. Teams Formation.cpp
 *
 *  Created on: Oct 26, 2017
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1e5 + 5;

int n, m, k, arr[MAXN];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	scanf("%d%d%d", &n, &k, &m);
	long long ans = 0;
	vector<pair<int, int>> cnt;
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	for (int i = 0; i < n; i++) {
		if (cnt.empty() || cnt.back().first != arr[i])
			cnt.push_back(make_pair(arr[i], 1));
		else
			cnt.back().second++;
		if (cnt.back().second == k)
			ans += 1ll * k * m, cnt.pop_back();
	}
	int i = 0, j = (int) cnt.size() - 1;
	while (i < j) {
		if (cnt[i].first != cnt[j].first)
			break;
		int temp = cnt[i].second + cnt[j].second;
		ans += 1ll * temp / k * k * (m - 1);
		if (temp % k)
			break;
		i++, j--;
	}
	if (i == j) {
		ans += 1ll * cnt[i].second * m / k * k;
		if (i && (1ll * cnt[i].second * m) % k == 0) {
			i--, j++;
			while (~i) {
				int temp = cnt[i].second + cnt[j].second;
				ans += 1ll * temp / k * k;
				if (temp % k)
					break;
				i--, j++;
			}
		}
	}
	printf("%lld\n", 1ll * n * m - ans);
	return 0;
}
