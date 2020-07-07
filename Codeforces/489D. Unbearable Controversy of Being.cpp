/*
 * 489D. Unbearable Controversy of Being.cpp
 *
 *  Created on: Feb 27, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 3e3 + 5;
const int MAXE = 3e4 + 5;

int head[MAXN], to[MAXE], nxt[MAXE], last;

void addEdge(int f, int t) {
	to[last] = t;
	nxt[last] = head[f];
	head[f] = last++;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	memset(head, -1, sizeof head);
	int n, m, a, b, cnt[MAXN];
	long long ans = 0;
	cin >> n >> m;
	while (m--) {
		cin >> a >> b;
		addEdge(a, b);
	}
	for (int i = 1; i <= n; i++) {
		queue<int> Q;
		for (int j = head[i]; j != -1; j = nxt[j])
			Q.push(to[j]);
		memset(cnt, 0, sizeof cnt);
		while (Q.size()) {
			int cur = Q.front();
			Q.pop();
			for (int j = head[cur]; j != -1; j = nxt[j])
				ans += (to[j] == i ? 0 : cnt[to[j]]++);
		}
	}
	cout << ans << endl;
	return 0;
}
