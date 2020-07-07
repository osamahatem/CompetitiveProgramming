/*
 * 850A. Five Dimensional Points.cpp
 *
 *  Created on: Sep 4, 2017
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1e3 + 5;

int n, p[MAXN][5];
bool bad[MAXN];

int dot(int a, int b, int c) {
	int ret = 0;
	for (int i = 0; i < 5; i++)
		ret += (p[b][i] - p[a][i]) * (p[c][i] - p[a][i]);
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < 5; j++)
			scanf("%d", &p[i][j]);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n && !bad[i]; j++) {
			if (i == j)
				continue;
			for (int k = j + 1; k < n && !bad[i]; k++) {
				if (i == k)
					continue;
				int d = dot(i, j, k);
				if (d > 0)
					bad[i] = 1;
				else
					bad[j] = bad[k] = 1;
			}
		}
	}
	vector<int> ans;
	for (int i = 0; i < n; i++)
		if (!bad[i])
			ans.push_back(i + 1);
	printf("%d\n", ans.size());
	for (int i = 0; i < (int) ans.size(); i++)
		printf("%d\n", ans[i]);
	return 0;
}
