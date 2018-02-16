/*
 * 5137 - Pyramids.cpp
 *
 *  Created on: Feb 16, 2018
 *      Author: Osama Hatem
 */
 
/*
This a simple 0/1 knapsack problem, but needs some optimisations to pass the
time and memory limits. The normal approach is to use an int array dp[sum][idx],
where sum is the number of cubes left and idx is the index of the largest
pyramid that can be used, to store the answer and use that to build the needed
answer. That won't fit in the available memory though, but the answer is at most
6, so we can use a char array instead. A better optimisation is to use iterative
dp to remove the second dimension, and use a bitset to store a bool that
indicates the states that belong to the optimal answer.
*/

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1e6 + 5;
const int INF = 100;

struct pyr {
	int cnt, h, t;

	bool operator <(const pyr &rhs) const {
		return make_pair(cnt, t) < make_pair(rhs.cnt, rhs.t);
	}
};

vector<pyr> all;
int dp[MAXN];
bitset<MAXN> vis[350];

void trace(int sum, int idx) {
	if (!sum)
		return;
	if (vis[idx][sum]) {
		cout << " " << all[idx].h << "LH"[all[idx].t];
		trace(sum - all[idx].cnt, idx - 1);
		return;
	}
	trace(sum, idx - 1);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	for (int i = 2, tot = 1; tot < MAXN; i++) {
		tot += i * i;
		all.push_back(pyr { tot, i, 1 });
	}
	for (int i = 3, tot = 1; tot < MAXN; i += 2) {
		tot += i * i;
		all.push_back(pyr { tot, i, 0 });
	}
	for (int i = 4, tot = 4; tot < MAXN; i += 2) {
		tot += i * i;
		all.push_back(pyr { tot, i, 0 });
	}
	sort(all.begin(), all.end());

	fill(dp, dp + MAXN, INF);
	dp[0] = 0;
	for (int i = 0; i < (int) all.size(); i++)
		for (int s = MAXN - 1; s >= all[i].cnt; s--)
			if (dp[s - all[i].cnt] + 1 <= dp[s])
				dp[s] = dp[s - all[i].cnt] + 1, vis[i][s] = 1;

	int n, T = 0;
	while (cin >> n, n) {
		cout << "Case " << ++T << ":";
		if (dp[n] == INF)
			cout << " impossible";
		else
			trace(n, (int) all.size() - 1);
		cout << endl;
	}
	return 0;
}
