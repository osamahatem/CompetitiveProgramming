/*
 * 128C. Games with Rectangle.cpp
 *
 *  Created on: Jun 20, 2018
 *      Author: Osama Hatem
 */

/*
 * The straightforward approach is a DP where f(x, y, z) is the number of ways
 * to play the game with a rectangle of dimensions x and y, with z steps left.
 * f(x, y, z) = sum of [(x - i - 1) * (y - j - 1) * f(x, y, z - 1)] for all i, j
 * such that 1 <= i <= x - 2, 1 <= j <= y - 2.
 * This approach has O(n ^ 5) time complexity and O(n ^ 3) space complexity.
 *
 * The first optimisation is that the height and width of new rectangles are
 * independent and can be separated. We modify our DP to be f(x, z): the number
 * of ways to shrink a dimension of length x over z steps, meeting the game
 * requirements (x' <= x - 2).
 * f(x, z) = sum of [(x - i - 1) * f(i, z - 1)] for all i such that
 * 1 <= i <= x - 2. The desired answer would be f(n, k) * f(m, k).
 * The solution now has O(n ^ 3) time complexity and O(n ^ 2) space complexity.
 *
 * The second optimisation is in noticing the following:
 * f(x, z) - f(x - 1, z) = sum of [f(i, z - 1)] for all i such that
 * 1 <= i <= x - 2.
 * This allows us to calculate the value of f(x, z) in O(1) by maintaining a
 * cumulative sum. This reduces time complexity to O(n ^ 2).
 *
 * It is possible to reduce space complexity to O(n).
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MOD = 1e9 + 7;

int n, m, k;
int dp[1005][1005];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> n >> m >> k;
	if (m > n)
		swap(n, m);

	memset(dp[0], 0, sizeof dp[0]);
	memset(dp[1], 0, sizeof dp[1]);
	memset(dp[2], 0, sizeof dp[2]);
	for (int i = 1; i <= n; i++)
		dp[i][0] = 1;

	for (int j = 1; j <= k; j++) {
		int sum = 0, ans = 0;
		for (int i = 3; i <= n; i++) {
			sum = (sum + dp[i - 2][j - 1]) % MOD;
			ans = (ans + sum) % MOD;
			dp[i][j] = ans;
		}
	}
	cout << 1ll * dp[n][k] * dp[m][k] % MOD << endl;
	return 0;
}
