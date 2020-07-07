/*
 * Goodland Electricity.cpp
 *
 *  Created on: Jul 12, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1e5 + 5;

bool tow[MAXN];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n, k;
	vector<int> all;
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++)
		scanf("%d", &tow[i]);
	int tar = k - 1, last = -1, ans = 0, used = -1;
	for (int i = 0; i < n; i++) {
		if (tow[i] == 1)
			last = i;
		if (i > tar) {
			printf("-1\n");
			return 0;
		}
		if (tar == i) {
			if (last == -1) {
				printf("-1\n");
				return 0;
			}
			ans++;
			used = last;
			tar = last + 2 * k - 1;
		}
	}
	if (used + k < n) {
		if (last + k >= n)
			ans++;
		else {
			printf("-1\n");
			return 0;
		}
	}
	printf("%d\n", ans);
	return 0;
}
