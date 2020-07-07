/*
 * GOODSET.cpp
 *
 *  Created on: Jun 2, 2017
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 101;
const int LIM = 501;

int n, arr[MAXN];
bool vis[LIM];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	for (int i = 1, sz = 0; sz < MAXN; i++) {
		if (vis[i])
			continue;
		arr[sz++] = i;
		for (int j = 0; j + 1 < sz; j++)
			if (i + arr[j] < LIM)
				vis[i + arr[j]] = 1;
	}
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			if (i)
				printf(" ");
			printf("%d", arr[i]);
		}
		printf("\n");
	}
	return 0;
}
