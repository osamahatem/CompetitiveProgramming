/*
 * F. Illumination.cpp
 *
 *  Created on: Oct 16, 2017
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1005;

int n, l, r;
pair<int, int> lamps[MAXN];
vector<int> adj[MAXN << 1];
int index[MAXN << 1], low[MAXN << 1], scc_id[MAXN << 1], id, scc;
stack<int> S;
bool inS[MAXN << 1];

bool conflict(int x, int y) {
	if (x > y)
		swap(x, y);
	return x + r >= y - r;
}

void tarjan(int idx) {
	index[idx] = low[idx] = ++id;
	S.push(idx), inS[idx] = true;
	for (auto ch : adj[idx]) {
		if (index[ch] == 0) {
			tarjan(ch);
			low[idx] = min(low[idx], low[ch]);
		} else if (inS[ch]) {
			low[idx] = min(low[idx], index[ch]);
		}
	}
	if (index[idx] == low[idx]) {
		scc++;
		int cur;
		do {
			cur = S.top();
			S.pop(), inS[cur] = false;
			scc_id[cur] = scc;
		} while (cur != idx);
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	scanf("%d%d%d", &n, &r, &l);
	for (int i = 0; i < l; i++)
		scanf("%d%d", &lamps[i].first, &lamps[i].second);
	for (int i = 0; i < l; i++) {
		for (int j = i + 1; j < l; j++) {
			if (lamps[i].first == lamps[j].first
					&& conflict(lamps[i].second, lamps[j].second))
				adj[i].push_back(j + l), adj[j].push_back(i + l);
			if (lamps[i].second == lamps[j].second
					&& conflict(lamps[i].first, lamps[j].first))
				adj[i + l].push_back(j), adj[j + l].push_back(i);
		}
	}
	for (int i = 0; i < l * 2; i++)
		if (index[i] == 0)
			tarjan(i);
	bool ans = true;
	for (int i = 0; i < l; i++)
		if (scc_id[i] == scc_id[i + l])
			ans = false;
	printf("%s\n", ans ? "YES" : "NO");
	return 0;
}
