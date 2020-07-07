/*
 * 6122 - Babs' Box Boutique.cpp
 *
 *  Created on: Nov 11, 2014
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int n, boxes[10][3], dp[21][21][1024];

int solve(int L, int W, int mask) {
	int &ret = dp[L][W][mask];
	if (ret != -1)
		return ret;
	ret = 0;
	for (int i = 0; i < n; i++) {
		if (mask & (1 << i))
			continue;
		for (int l = 0; l < 3; l++)
			for (int w = 0; w < 3; w++)
				if (w != l && boxes[i][l] <= L && boxes[i][w] <= W)
					ret = max(ret,
							1
									+ solve(boxes[i][l], boxes[i][w],
											mask | (1 << i)));
	}
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int tc = 0;
	while (cin >> n, n) {
		memset(dp, -1, sizeof dp);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < 3; j++)
				cin >> boxes[i][j];
		cout << "Case " << ++tc << ": " << solve(20, 20, 0) << endl;
	}
	return 0;
}
