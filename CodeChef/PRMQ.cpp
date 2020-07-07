/*
 * PRMQ.cpp
 *
 *  Created on: Jun 2, 2017
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1e5 + 5;
const int MAXV = 1e6 + 5;
const int GROUP = 317;

bool isComp[MAXV];
int factor[MAXV];
vector<int> primes;
int N, Q;

void init() {
	isComp[0] = isComp[1] = 1;
	primes.push_back(0);
	for (int i = 2; i < MAXV; i++) {
		if (!isComp[i]) {
			primes.push_back(i);
			for (int j = i; j < MAXV; j += i)
				isComp[j] = 1, factor[j] = i;
		}
	}
}

int getRnk(int x) {
	return upper_bound(primes.begin(), primes.end(), x) - primes.begin() - 1;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	init();
	scanf("%d", &N);
	vector<vector<int>> groups(GROUP, vector<int>(primes.size(), 0));
	vector<vector<pair<int, int>>> factors(N, vector<pair<int, int>>());
	int x, y, l, r, idx = 0, curGrp = 0;
	for (int i = 0; i < N; i++) {
		scanf("%d", &x);
		while (x > 1) {
			int rnk = getRnk(factor[x]);
			if (factors[i].empty() || factors[i].back().first != factor[x])
				factors[i].push_back( { factor[x], 1 });
			else
				factors[i].back().second++;
			groups[curGrp][rnk]++;
			x /= factor[x];
		}
		idx++;
		if (idx == GROUP)
			idx = 0, curGrp++;
	}
	for (int i = 0; i < GROUP; i++)
		for (int j = 1; j < (int) primes.size(); j++)
			groups[i][j] += groups[i][j - 1];
	scanf("%d", &Q);
	while (Q--) {
		scanf("%d%d%d%d", &l, &r, &x, &y);
		l--, r--;
		int xx = getRnk(x - 1), yy = getRnk(y);
		int ans = 0;
		for (int i = 0; i < GROUP; i++) {
			int s = i * GROUP, e = (i + 1) * GROUP - 1;
			if (r < s || l > e)
				continue;
			if (s >= l && e <= r) {
				ans += groups[i][yy] - groups[i][xx];
			} else {
				int ll = max(l, s), rr = min(r, e);
				for (int j = ll; j <= rr; j++)
					for (int k = 0; k < (int) factors[j].size(); k++)
						if (factors[j][k].first >= x
								&& factors[j][k].first <= y)
							ans += factors[j][k].second;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
