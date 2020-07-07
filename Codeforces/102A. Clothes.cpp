/*
 * 102A. Clothes.cpp
 *
 *  Created on: Feb 9, 2017
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

bool mat[105][105];
int arr[105];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n, m, ans = -1;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	while (m--) {
		int a, b;
		scanf("%d%d", &a, &b);
		a--, b--;
		mat[a][b] = mat[b][a] = 1;
	}
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			for (int k = j + 1; k < n; k++)
				if (mat[i][j] && mat[i][k] && mat[j][k])
					ans = ans == -1 ?
							arr[i] + arr[j] + arr[k] :
							min(ans, arr[i] + arr[j] + arr[k]);
	printf("%d\n", ans);
	return 0;
}
