/*
 * 429C. Guess the Tree.cpp
 *
 *  Created on: Jul 20, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int N, c[25];
map<int, bool> dp;

bool solve(int activeMask) {
	int idx = N;
	for (int i = N - 1; !(activeMask & (1 << i)) && i >= 0; i--)
		idx = i;
	if (idx == N)
		return activeMask == 1 << (N - 1);
	if (dp.count(activeMask))
		return dp[activeMask];
	bool ret = false;
	vector<int> active;
	for (int i = 0; i < N; i++)
		if ((1 << i) & activeMask)
			active.push_back(i);
	int sz = active.size();
	for (int i = 3; !ret && i < (1 << sz); i++) {
		if (!(i & (i - 1)))
			continue;
		int tempSum = 0, newMask = activeMask | (1 << idx);
		for (int j = 0; j < sz; j++)
			if (i & (1 << j))
				tempSum += c[active[j]], newMask ^= 1 << active[j];
		if (tempSum != c[idx] - 1)
			continue;
		ret |= solve(newMask);
	}
	return dp[activeMask] = ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> c[i];
	sort(c, c + N);
	int mask = 0, cur = 0;
	for (; cur < N && c[cur] == 1; cur++)
		mask |= 1 << cur;
	cout << (solve(mask) ? "YES" : "NO") << endl;
	return 0;
}
