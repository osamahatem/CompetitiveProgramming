/*
 * 463C. Gargari and Bishops.cpp
 *
 *  Created on: Jul 13, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int n, grid[2000][2000];
long long sum1[4000], sum2[4000];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			scanf("%d", &grid[i][j]);
			sum1[i + j] += grid[i][j];
			sum2[i - j + n] += grid[i][j];
		}
	long long maxOdd = -1, maxEven = -1;
	int xo = -1, yo = -1, xe = -1, ye = -1;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (((i + j) & 1)
					&& sum1[i + j] + sum2[i - j + n] - grid[i][j] > maxOdd)
				maxOdd = sum1[i + j] + sum2[i - j + n] - grid[i][j], xo = i, yo =
						j;
			else if (!((i + j) & 1)
					&& sum1[i + j] + sum2[i - j + n] - grid[i][j] > maxEven)
				maxEven = sum1[i + j] + sum2[i - j + n] - grid[i][j], xe = i, ye =
						j;
	printf("%lld\n%d %d %d %d\n", maxOdd + maxEven, ++xo, ++yo, ++xe, ++ye);
	return 0;
}
