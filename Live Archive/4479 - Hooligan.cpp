/*
 * 4479 - Hooligan.cpp
 *
 *  Created on: Sep 21, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int N, M, G, games[44][44], score[44];

pair<int, int> getTeams() {
	int a = -1, b = -1;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			if (i == 0 && games[i][j]) {
				games[i][j]--;
				games[j][i]--;
				return make_pair(i, j);
			}
			if (games[i][j]) {
				if (a == -1
						|| (score[i] > score[a]
								|| (score[i] == score[a] && score[j] > score[b])))
					a = i, b = j;
			}
		}
	if (a == -1)
		return make_pair(a, b);
	games[a][b]--;
	games[b][a]--;
	return make_pair(a, b);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	while (scanf("%d %d %d", &N, &M, &G), N) {
		memset(score, 0, sizeof score);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++)
				games[i][j] = M;
			games[i][i] = 0;
		}
		for (int i = 0; i < G; i++) {
			int a, b;
			char c[3];
			scanf("%d %s %d", &a, c, &b);
			games[a][b]--;
			games[b][a]--;
			if (c[0] == '<')
				score[b] += 2;
			else
				score[a]++, score[b]++;
		}
		pair<int, int> team;
		while (team = getTeams(), team.first != -1) {
			if (team.first == 0)
				score[0] += 2;
			else {
				if (score[team.first] == score[team.second])
					score[team.first]++, score[team.second]++;
				else
					score[team.second] += 2;
			}
		}
		bool flag = 1;
		for (int i = 1; i < N; i++)
			if (score[i] >= score[0])
				flag = 0;
		printf("%c\n", "NY"[flag]);
	}
	return 0;
}
