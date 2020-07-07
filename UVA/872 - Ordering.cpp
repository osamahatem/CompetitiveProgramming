/*
 * 872 - Ordering.cpp
 *
 *  Created on: Sep 16, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

char in[250];
bool pre[26][26], valid[26];
int vis[26];
string out;

bool topo(int n) {
	vis[n] = 1;
	for (int i = 0; i < 26; i++) {
		if (!pre[n][i])
			continue;
		if (vis[i] == 1)
			return false;
		if (!vis[i] && !topo(i))
			return false;
		for (int j = 0; j < 26; j++)
			pre[n][j] |= pre[i][j];
	}
	vis[n] = 2;
	return true;
}

void printOrders(int mask) {
	bool done = 1;
	for (int i = 0; i < 26; i++)
		if (valid[i] && !(mask & (1 << i)))
			done = 0;
	if (done) {
		printf("%s\n", out.c_str());
		return;
	}
	if (mask)
		out += " ";
	for (int i = 0; i < 26; i++) {
		if (!valid[i] || (mask & (1 << i)))
			continue;
		bool preDone = 1;
		for (int j = 0; j < 26; j++)
			if (pre[i][j] && !(mask & (1 << j)))
				preDone = 0;
		if (!preDone)
			continue;
		out += 'A' + i;
		printOrders(mask | (1 << i));
		out.pop_back();
	}
	if (mask)
		out.pop_back();
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int T;
	scanf("%d", &T);
	gets(in);
	while (T--) {
		memset(vis, 0, sizeof vis);
		memset(valid, 0, sizeof valid);
		memset(pre, 0, sizeof pre);
		gets(in);
		gets(in);
		int len = strlen(in);
		for (int i = 0; i < len; i += 2)
			valid[in[i] - 'A'] = 1;
		gets(in);
		len = strlen(in);
		for (int i = 0; i < len; i += 4)
			pre[in[i + 2] - 'A'][in[i] - 'A'] = 1;
		bool orderExists = 1;
		for (int i = 0; i < 26; i++)
			if (valid[i] && !vis[i])
				orderExists &= topo(i);
		if (!orderExists) {
			printf("NO\n");
		} else {
			printOrders(0);
		}
		if (T)
			printf("\n");
	}
	return 0;
}
