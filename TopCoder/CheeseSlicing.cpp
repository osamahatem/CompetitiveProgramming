/*
 * CheeseSlicing.cpp
 *
 *  Created on: Apr 1, 2017
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

class CheeseSlicing {
	int dp[101][101][101];

	int solve(int x, int y, int z, int s) {
		if (y < x)
			swap(x, y);
		if (z < x)
			swap(x, z);
		if (z < y)
			swap(y, z);
		if (x < s)
			return 0;
		int &ret = dp[x][y][z];
		if (~ret)
			return ret;
		ret = y * z;
		for (int i = 1; i < x; i++)
			ret = max(ret, solve(i, y, z, s) + solve(x - i, y, z, s));
		for (int i = 1; i < y; i++)
			ret = max(ret, solve(x, i, z, s) + solve(x, y - i, z, s));
		for (int i = 1; i < z; i++)
			ret = max(ret, solve(x, y, i, s) + solve(x, y, z - i, s));
		return ret;
	}
public:
	int totalArea(int A, int B, int C, int S) {
		memset(dp, -1, sizeof dp);
		return solve(A, B, C, S);
	}
};

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	return 0;
}
