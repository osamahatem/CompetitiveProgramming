/*
 * B. Highlight.cpp
 *
 *  Created on: Sep 10, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int col[10005];
char in[10005], p[3][10005];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	freopen("highlight.in", "r", stdin);
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		printf("Case %d:\n", t);
		int h, p1, p2, p3;
		scanf("%d%d%d%d", &h, &p1, &p2, &p3);
		for (int i = 0; i < h; i++)
			scanf("%d", &col[i]);
		gets(in);
		for (int i = 0; i < 3; i++) {
			int cur = 0;
			gets(in);
			while (gets(in), in[0] != '*')
				for (int c = 0; in[c]; c++)
					p[i][cur++] = in[c];
		}
		for (int i = 0; i < 3; i++) {
			printf("**page**\n");
			int temp = (!i ? 1 << 16 : (i == 1 ? 1 << 8 : 1));
			int pp = (!i ? p1 : (i == 1 ? p2 : p3));
			int cur = 0;
			for (int j = 0; j < pp; j++)
				if ((col[j] / temp) % 256 > 85)
					p[i][cur++] = p[i][j];
			p[i][cur] = 0;
			printf("%s\n**end**\n", p[i]);
		}
	}
	return 0;
}
