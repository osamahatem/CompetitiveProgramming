/*
 * K. Wiki Lists.cpp
 *
 *  Created on: Nov 16, 2017
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

char in[1005][1005];
int n;

void solve(int s, int e, int d) {
	for (int i = s; i <= e; i++) {
		int ee = i + 1;
		while (ee <= e && in[ee][d] == in[i][d]
				&& (in[i][d] == '*' || in[i][d] == '#'))
			ee++;
		if (ee - i > 1) {
			if (d)
				printf("<li>\n");
			printf("%s\n", in[i][d] == '#' ? "<ol>" : "<ul>");
			solve(i, ee - 1, d + 1);
			printf("%s\n", in[i][d] == '#' ? "</ol>" : "</ul>");
			if (d)
				printf("</li>\n");
			i = ee - 1;
		} else {
			if (d)
				printf("<li>\n");
			printf("%s\n", in[i] + d);
			if (d)
				printf("</li>\n");
		}
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	while (scanf("%s", in[n]) != EOF)
		n++;
	solve(0, n - 1, 0);
	return 0;
}
