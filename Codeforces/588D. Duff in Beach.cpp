/*
 * 588D. Duff in Beach.cpp
 *
 *  Created on: Oct 16, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1e6 + 6;
const int MOD = 1000000007;

int N, k, arr[MAXN], temp[MAXN], idx[MAXN], last[MAXN];
long long l;
vector<int> rnk;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	scanf("%d%I64d%d", &N, &l, &k);
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
		rnk.push_back(arr[i]);
	}
	sort(rnk.begin(), rnk.end());
	rnk.erase(unique(rnk.begin(), rnk.end()), rnk.end());
	for (int i = 0; i < N; i++)
		idx[i] = lower_bound(rnk.begin(), rnk.end(), arr[i]) - rnk.begin();
	long long rnds = (l + N - 1) / N, ans = 0;
	for (int kk = 1; kk <= min(1ll * k, rnds - 1); kk++) {
		for (int i = 0; i < N; i++)
			temp[idx[i]] = (last[idx[i]] + temp[idx[i]] + (kk == 1)) % MOD;
		for (int i = 0; i < (int) rnk.size(); i++) {
			last[i] = temp[i];
			temp[i] = 0;
		}
		for (int i = (int) rnk.size() - 1; i >= 0; i--)
			last[i] = (last[i] + last[i + 1]) % MOD;
		ans = (ans + last[0] * ((rnds - kk) % MOD)) % MOD;
	}
	int lim = (l - 1) % N;
	memset(last, 0, sizeof last);
	for (int kk = 1; kk <= min(1ll * k, rnds); kk++) {
		for (int i = 0; i < N; i++)
			temp[idx[i]] = (last[idx[i]] + temp[idx[i]] + (kk == 1 && i <= lim))
					% MOD;
		for (int i = 0; i < (int) rnk.size(); i++) {
			last[i] = temp[i];
			temp[i] = 0;
		}
		for (int i = (int) rnk.size() - 1; i >= 0; i--)
			last[i] = (last[i] + last[i + 1]) % MOD;
		ans = (ans + last[0]) % MOD;
	}
	printf("%I64d\n", ans);
	return 0;
}
