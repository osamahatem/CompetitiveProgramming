/*
 * 10171 - Meeting Prof. Miguel....cpp
 *
 *  Created on: Sep 15, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int INF = 63 * (1 + (1 << 8) + (1 << 16) + (1 << 24));

int n, c, dist1[26][26], dist2[26][26];
char t, d, u, v;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	while (scanf("%d%*c", &n), n) {
		memset(dist1, 63, sizeof dist1);
		memset(dist2, 63, sizeof dist2);
		for (int i = 0; i < 26; i++)
			dist1[i][i] = dist2[i][i] = 0;
		while (n--) {
			scanf("%c%*c%c%*c%c%*c%c%*c%d%*c", &t, &d, &u, &v, &c);
			if (t == 'Y') {
				dist1[u - 'A'][v - 'A'] = min(dist1[u - 'A'][v - 'A'], c);
				if (d == 'B')
					dist1[v - 'A'][u - 'A'] = min(dist1[v - 'A'][u - 'A'], c);
			} else {
				dist2[u - 'A'][v - 'A'] = min(dist2[u - 'A'][v - 'A'], c);
				if (d == 'B')
					dist2[v - 'A'][u - 'A'] = min(dist2[v - 'A'][u - 'A'], c);
			}
		}
		for (int k = 0; k < 26; k++)
			for (int i = 0; i < 26; i++)
				for (int j = 0; j < 26; j++) {
					dist1[i][j] = min(dist1[i][j], dist1[i][k] + dist1[k][j]);
					dist2[i][j] = min(dist2[i][j], dist2[i][k] + dist2[k][j]);
				}
		scanf("%c%*c%c", &u, &v);
		int s = u - 'A', e = v - 'A', mini = INF;
		for (int i = 0; i < 26; i++)
			mini = min(mini, dist1[s][i] + dist2[e][i]);
		if (mini == INF) {
			printf("You will never meet.\n");
		} else {
			printf("%d", mini);
			for (int i = 0; i < 26; i++)
				if (dist1[s][i] + dist2[e][i] == mini)
					printf(" %c", 'A' + i);
			printf("\n");
		}
	}
	return 0;
}
