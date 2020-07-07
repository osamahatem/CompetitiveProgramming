/*
 * 11902 - Dominator.cpp
 *
 *  Created on: Sep 11, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int N, adj[100][100], vis[100], id;
bool ans[100][100], canReach[100];
string line;

void DFS(int n) {
	vis[n] = id;
	for (int i = 0; i < N; i++)
		if (adj[n][i] && vis[i] != id)
			DFS(i);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		memset(ans, 0, sizeof ans);
		scanf("%d", &N);
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				scanf("%d", &adj[i][j]);
		id++;
		DFS(0);
		for (int i = 0; i < N; i++)
			canReach[i] = vis[i] == id;
		for (int i = 1; i < N; i++) {
			if (!canReach[i])
				continue;
			vis[i] = ++id;
			DFS(0);
			for (int j = 0; j < N; j++)
				ans[i][j] = (canReach[j] && vis[j] != id);
		}
		for (int i = 0; i < N; i++)
			if (canReach[i])
				ans[0][i] = ans[i][i] = 1;
		line.clear();
		line += "+";
		for (int i = 1; i < 2 * N; i++)
			line += "-";
		line += "+";
		printf("Case %d:\n%s\n", t, line.c_str());
		for (int i = 0; i < N; i++) {
			printf("|");
			for (int j = 0; j < N; j++)
				printf("%c|", ans[i][j] ? 'Y' : 'N');

			printf("\n%s\n", line.c_str());
		}
	}
	return 0;
}
