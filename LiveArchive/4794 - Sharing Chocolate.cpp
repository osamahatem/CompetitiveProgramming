/*
 * 4794 - Sharing Chocolate.cpp
 *
 *  Created on: Feb 16, 2018
 *      Author: Osama Hatem
 */
 
/*
The straight-forward solution would be a dp with state of width, height, and a
mask representing the pieces left. At each state, we iterate over all possible
cuts and sub-masks, to divide the remaining piece on the 2 resulting parts. This
is too slow though, namely O(D^3 * 3^N), where D is the maximum dimension of the
chocolate piece and N is the number of required resulting pieces.
The first possible optimisation is eliminating a dimension from the state; given
the mask in the state, the current area is known and the second dimension can be
calculated from the first. This reduces complexity to O(D^2 * 3^N).
The second optimisation is realising that we don't need to try all horizontal
and vertical cuts for any given sub-mask, and that only one cut in each
direction is possible, at best. To see this, consider any sub-mask: we need the
result of the cut to have equal area to the sum of pieces in the sub-mask.
Assume we're doing a horizontal cut, the width remains unchanged and so, the new
height must be equal to area / width; only that cut is valid, and the same goes
for vertical cuts.
This reduces the complexity to O(D * 3^N). This is still a bit too much to pass
in time, but the code only tries valid cuts, which prunes a lot of states; the
upper bound complexity is much lower in practice.
*/

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int n, x, y, sz[15], area[1 << 15], dp[101][1 << 15];

int solve(int x, int mask) {
	if (!(mask & (mask - 1)))
		return 1;
	int y = area[mask] / x;
	if (x > y)
		swap(x, y);
	int &ret = dp[x][mask];
	if (~ret)
		return ret;
	for (int m = mask & (mask - 1); m; m = (m - 1) & mask) {
		if (area[m] % x == 0 && solve(x, m) && solve(x, mask ^ m))
			return ret = 1;
		if (area[m] % y == 0 && solve(y, m) && solve(y, mask ^ m))
			return ret = 1;
	}
	return ret = 0;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int T = 0;
	while (cin >> n, n) {
		cin >> x >> y;
		for (int i = 0; i < n; i++)
			cin >> sz[i];

		memset(area, 0, sizeof area);
		for (int i = 0; i < (1 << n); i++)
			for (int j = 0; j < n; j++)
				area[i] += sz[j] * ((i >> j) & 1);

		memset(dp, -1, sizeof dp);
		bool ans = (area[(1 << n) - 1] == x * y) && (solve(x, (1 << n) - 1));
		cout << "Case " << ++T << ": " << (ans ? "Yes" : "No") << endl;
	}
	return 0;
}
