/*
 * RandomSwaps.cpp
 *
 *  Created on: Nov 20, 2017
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

class RandomSwaps {
public:
	double getProbability(int len, int cnt, int a, int b) {
		double dp[2][len], sum = 1.0;
		for (int i = 0; i < len; i++)
			dp[0][i] = 0.0;
		dp[0][b] = 1.0;
		for (int c = 1; c <= cnt; c++) {
			int i = c & 1, ii = (c & 1) ^ 1;
			for (int j = 0; j < len; j++) {
				dp[i][j] = (sum - dp[ii][j]) * 2.0 / (len * (len - 1));
				dp[i][j] += dp[ii][j] * (len - 2) / len;
			}
			sum = 0.0;
			for (int j = 0; j < len; j++)
				sum += dp[i][j];
		}
		return dp[cnt & 1][a];
	}
};

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	RandomSwaps myClass = RandomSwaps();
	cout << fixed << setprecision(9);
	cout << myClass.getProbability(5, 1, 0, 0) << endl;
	cout << myClass.getProbability(5, 1, 0, 3) << endl;
	cout << myClass.getProbability(5, 2, 0, 0) << endl;
	cout << myClass.getProbability(100, 500, 3, 3) << endl;
	return 0;
}
