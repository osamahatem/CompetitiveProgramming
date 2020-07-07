/*
 * 259 - Software Allocation.cpp
 *
 *  Created on: Oct 23, 2014
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int ALPHA = 26;
const int MAXN = 40;
const int MAXE = 300;
const int SRC = MAXN - 1;
const int SNK = MAXN - 2;

int head[MAXN], to[MAXE], cap[MAXE], nxt[MAXE], last;
bool vis[MAXN];
char p[10];

void init() {
	memset(head, -1, sizeof head);
	memset(p, '_', sizeof p);
	last = 0;
}

void addEdge(int t, int f, int c = 0) {
	nxt[last] = head[f];
	to[last] = t;
	cap[last] = c;
	head[f] = last++;
}

void addAugEdge(int t, int f, int c) {
	addEdge(f, t, c);
	addEdge(t, f);
}

void parse(string in) {
	int n = in[0] - 'A';
	int c = in[1] - '0';
	addAugEdge(SRC, n, c);
	for (int i = 3; i + 1 < (int) in.size(); i++)
		addAugEdge(n, in[i] - '0' + ALPHA, 1);
}

bool DFS(int cur) {
	if (cur == SNK)
		return true;
	vis[cur] = 1;
	for (int i = head[cur]; i != -1; i = nxt[i])
		if (!vis[to[i]] && cap[i] && DFS(to[i])) {
			if (to[i] >= ALPHA && to[i] < ALPHA + 10)
				p[to[i] - ALPHA] = cur + 'A';
			cap[i]--;
			cap[i ^ 1]++;
			return true;
		}
	return false;
}

int maxFlow() {
	int ans = 0;
	memset(vis, 0, sizeof vis);
	while (DFS(SRC)) {
		ans++;
		memset(vis, 0, sizeof vis);
	}
	return ans;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	string in;
	while (getline(cin, in)) {
		init();
		int sum = 0;
		do {
			parse(in);
			sum += in[1] - '0';
		} while (getline(cin, in) && in.size());
		for (int i = 0; i < 10; i++)
			addAugEdge(ALPHA + i, SNK, 1);
		int ans = maxFlow();
		if (ans < sum)
			cout << "!\n";
		else {
			for (int i = 0; i < 10; i++)
				cout << p[i];
			cout << endl;
		}
	}
	return 0;
}
