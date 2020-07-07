/*
 * 2004. Scientists from Spilkovo.cpp
 *
 *  Created on: Aug 2, 2014
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

bool vis[1 << 20];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
#endif

	int n;
	scanf("%d", &n);
	int suffix = (1 << (n - 1)) - 1, cur = (1 << n) - 1;
	vis[cur] = 1;
	string ans = "";
	for (int i = 0; i < n; i++)
		ans += '1';
	while (1) {
		cur &= suffix;
		cur <<= 1;
		if (!vis[cur])
			ans += '0', vis[cur] = 1;
		else if (!vis[++cur])
			ans += '1', vis[cur] = 1;
		else
			break;
	}
	printf("%s\n", ans.c_str());
	return 0;
}
