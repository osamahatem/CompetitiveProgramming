/*
 * 698B. Fix a Tree.cpp
 *
 *  Created on: Jul 19, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int n, p[200005], r = -1, ans, vis[200005], id;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &p[i]);
		p[i]--;
		if (p[i] == i)
			r = i;
	}
	for (int i = 0; i < n; i++) {
		if (vis[i] || i == r)
			continue;
		id++;
		int x = i;
		while (!vis[x] && x != r) {
			vis[x] = id;
			x = p[x];
		}
		if (vis[x] == id && x != r) {
			if (r == -1)
				r = x;
			p[x] = r, ans++;
		}
	}
	printf("%d\n", ans);
	for (int i = 0; i < n; i++) {
		if (i)
			printf(" ");
		printf("%d", ++p[i]);
	}
	printf("\n");
	return 0;
}
