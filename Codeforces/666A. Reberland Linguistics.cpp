/*
 * 666A. Reberland Linguistics.cpp
 *
 *  Created on: Apr 29, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

char in[10005];
int len;
set<string> ans;
bool vis[10005][2];
string temp;

void solve(int idx, int last) {
	if (idx < 5 || vis[idx][last])
		return;
	vis[idx][last] = 1;
	string nxt = temp.substr(idx + 1, 2 + last);
	string cur = temp.substr(idx - 1, 2);
	if (idx - 2 > 3 && cur != nxt)
		solve(idx - 2, 0), ans.insert(cur);
	cur = temp.substr(idx - 2, 3);
	if (idx - 3 > 3 && cur != nxt)
		solve(idx - 3, 1), ans.insert(cur);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	scanf("%s", in);
	temp = in;
	len = strlen(in);
	solve(len - 1, 0);
	printf("%d\n", ans.size());
	for (auto it = ans.begin(); it != ans.end(); it++)
		printf("%s\n", it->c_str());
	return 0;
}
