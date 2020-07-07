/*
 * 624C. Graph and String.cpp
 *
 *  Created on: Mar 22, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 505;

int val[MAXN], mat[MAXN][MAXN];
char ans[MAXN];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n, m, a, b;
	memset(val, -1, sizeof val);
	scanf("%d%d", &n, &m);
	ans[n] = 0;
	for (int i = 0; i < m; i++) {
		scanf("%d%d", &a, &b);
		a--, b--;
		mat[a][b] = mat[b][a] = 1;
	}
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++) {
			if (mat[i][j])
				continue;
			if (val[i] != -1 && val[j] != -1 && val[i] + val[j] != 2) {
				printf("No\n");
				return 0;
			}
			if (val[i] == -1 && val[j] == -1)
				val[i] = 0, val[j] = 2;
			else if (val[i] != -1)
				val[j] = 2 - val[i];
			else
				val[i] = 2 - val[j];
		}
	for (int i = 0; i < n; i++)
		if (val[i] == -1)
			val[i] = 1;
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			if ((mat[i][j] && abs(val[i] - val[j]) > 1)
					|| (!mat[i][j] && abs(val[i] - val[j]) < 2)) {
				printf("No\n");
				return 0;
			}
	for (int i = 0; i < n; i++)
		ans[i] = val[i] + 'a';
	printf("Yes\n%s\n", ans);
	return 0;
}
