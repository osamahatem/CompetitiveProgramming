/*
 * SRM545-D2-1000 - SpacetskE.cpp
 *
 *  Created on: Aug 13, 2016
 *      Author: Osama Hatem
 */
 
/*
Iterate over all unique slopes. For each slope and for each launching point, add
to the answer the number of possibilities (integer points the line passes
through choose K). We don't need to strictly iterate over all launching points,
as the number of possibilities only change at multiples of delta x of the slope.
Complexity O(H * L * ln(L))
*/

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

class SpacetskE {
	static const int MOD = 1e9 + 7;
	static const int MAXN = 202;

	int nCr[MAXN][MAXN];

	void fill_nCr() {
		for (int i = 0; i < MAXN; i++) {
			nCr[i][0] = nCr[i][i] = 1;
			for (int j = 1; j < i; j++)
				nCr[i][j] = (nCr[i - 1][j] + nCr[i - 1][j - 1]) % MOD;
			for (int j = i + 1; j < MAXN; j++)
				nCr[i][j] = 0;
		}
	}

public:
	int countsets(int L, int H, int K) {
		if (K == 1)
			return (L + 1) * (H + 1);
		fill_nCr();
		int ret = 1ll * nCr[H + 1][K] * (L + 1) % MOD;
		for (int x = 1; x <= L; x++)
			for (int y = 1; y <= H; y++) {
				if (__gcd(x, y) > 1)
					continue;
				int yy = H / y + 1;
				for (int xx = 0; xx <= L; xx += x) {
					int choices = min(xx / x + 1, yy);
					ret = (ret
							+ 1ll * nCr[choices][K] * min(x, L - xx + 1) % MOD)
							% MOD;
				}
				for (int xx = L; xx >= 0; xx -= x) {
					int choices = min((L - xx) / x + 1, yy);
					ret = (ret + 1ll * nCr[choices][K] * min(x, xx + 1) % MOD)
							% MOD;
				}
			}
		return ret;
	}
};

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	return 0;
}
