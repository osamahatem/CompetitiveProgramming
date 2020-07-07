/*
 * 724D. Dense Subsequence.cpp
 *
 *  Created on: Feb 8, 2017
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1e5;

char str[MAXN];
bool vis[MAXN];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int m;
	scanf("%d%s", &m, str);
	int len = strlen(str), last = -1, idx = 0;
	char maxi = 'a';
	deque<int> Q;
	string ans = "";
	while (last + m < len) {
		while (idx <= last + m) {
			while (Q.size() && str[idx] <= str[Q.front()])
				Q.pop_front();
			Q.push_front(idx++);
		}
		while (Q.size() && Q.back() <= last)
			Q.pop_back();
		int x = Q.back();
		vis[x] = 1, ans += str[x], last = x, maxi = max(maxi, str[x]);
	}
	for (int i = 0; i < len; i++)
		if (!vis[i] && str[i] < maxi)
			ans += str[i];
	sort(ans.begin(), ans.end());
	printf("%s\n", ans.c_str());
	return 0;
}
