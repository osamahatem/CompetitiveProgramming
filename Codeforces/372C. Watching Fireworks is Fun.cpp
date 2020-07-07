/*
 * 372C. Watching Fireworks is Fun.cpp
 *
 *  Created on: Jul 15, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 15e4 + 5;

struct node {
	int a, b, t;
};

int N, m, d, dp[MAXN], temp[MAXN];
node arr[305];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	long long ans = 0;
	scanf("%d%d%d", &N, &m, &d);
	for (int i = 0; i < m; i++) {
		scanf("%d%d%d", &arr[i].a, &arr[i].b, &arr[i].t);
		ans += arr[i].b;
	}
	deque<pair<int, int>> S;
	for (int i = m - 2; i >= 0; i--) {
		int dt = arr[i + 1].t - arr[i].t, idx = arr[i + 1].a;
		S.clear();
		memset(temp, 127, sizeof temp);
		for (int nn = 1; nn <= N; nn++) {
			int s = max(1ll, 1ll * nn - 1ll * d * dt);
			int e = min(1ll * N, 1ll * nn + 1ll * d * dt);
			while (idx <= e) {
				while (S.size()
						&& S.front().first >= dp[idx] - arr[i + 1].a + idx)
					S.pop_front();
				S.push_front(make_pair(dp[idx] - arr[i + 1].a + idx, idx));
				idx++;
			}
			while (S.size() && S.back().second < s)
				S.pop_back();
			if (S.size())
				temp[nn] = S.back().first;
		}
		S.clear(), idx = arr[i + 1].a - 1;
		for (int nn = N; nn > 0; nn--) {
			int s = max(1ll, 1ll * nn - 1ll * d * dt);
			int e = min(1ll * N, 1ll * nn + 1ll * d * dt);
			while (idx >= s) {
				while (S.size()
						&& S.front().first >= dp[idx] - idx + arr[i + 1].a)
					S.pop_front();
				S.push_front(make_pair(dp[idx] - idx + arr[i + 1].a, idx));
				idx--;
			}
			while (S.size() && S.back().second > e)
				S.pop_back();
			if (S.size())
				temp[nn] = min(temp[nn], S.back().first);
		}
		memcpy(dp, temp, sizeof temp);
	}
	int aans = 1 << 30;
	for (int nn = 1; nn <= N; nn++)
		aans = min(aans, temp[nn] + abs(nn - arr[0].a));
	ans -= aans;
	printf("%lld\n", ans);
	return 0;
}
