/*
 * 853B. Jury Meeting.cpp
 *
 *  Created on: Sep 11, 2017
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1e5 + 5;
const int MAXT = 1e6 + 5;
const long long INF = 1e18;

int n, m, k, last[MAXN], lft, idx;
vector<pair<pair<int, int>, int>> in, out;
long long minIn[MAXT], minOut[MAXT], cur;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	scanf("%d%d%d", &n, &m, &k);
	while (m--) {
		int d, f, t, c;
		scanf("%d%d%d%d", &d, &f, &t, &c);
		if (f)
			in.push_back( { { d, c }, f });
		else
			out.push_back( { { d, c }, t });
	}
	sort(in.begin(), in.end());
	sort(out.begin(), out.end());
	memset(minIn, -1, sizeof minIn);
	memset(minOut, -1, sizeof minOut);
	memset(last, -1, sizeof last), lft = n, cur = 0, idx = 0;
	for (int i = 0; i < MAXT; i++) {
		while (idx < (int) in.size() && in[idx].first.first == i) {
			int c = in[idx].first.second, x = in[idx].second;
			if (last[x] == -1)
				last[x] = c, cur += c, lft--;
			else {
				cur += min(last[x], c) - last[x];
				last[x] = min(last[x], c);
			}
			idx++;
		}
		minIn[i] = (lft ? -1 : cur);
	}
	memset(last, -1, sizeof last), lft = n, cur = 0, idx = (int) out.size() - 1;
	for (int i = MAXT - 1; ~i; i--) {
		while (~idx && out[idx].first.first == i) {
			int c = out[idx].first.second, x = out[idx].second;
			if (last[x] == -1)
				last[x] = c, cur += c, lft--;
			else {
				cur += min(last[x], c) - last[x];
				last[x] = min(last[x], c);
			}
			idx--;
		}
		minOut[i] = (lft ? -1 : cur);
	}
	long long ans = INF;
	for (int s = 1, e = k; e + 1 < MAXT; s++, e++) {
		if (minIn[s - 1] == -1 || minOut[e + 1] == -1)
			continue;
		ans = min(ans, minIn[s - 1] + minOut[e + 1]);
	}
	ans = (ans == INF ? -1 : ans);
	printf("%lld\n", ans);
	return 0;
}
