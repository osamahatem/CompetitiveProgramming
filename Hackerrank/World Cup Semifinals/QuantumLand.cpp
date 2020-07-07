/*
 * QuantumLand.cpp
 *
 *  Created on: Sep 19, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1e5 + 5;

int to[MAXN], p[MAXN], lowlink[MAXN], idx[MAXN], _idx;
stack<int> S;
vector<vector<int>> components;
bool vis[MAXN], inS[MAXN];

void SCC(int node) {
	vis[node] = 1;
	lowlink[node] = idx[node] = _idx++;
	S.push(node), inS[node] = 1;
	if (idx[to[node]] == -1) {
		SCC(to[node]);
		lowlink[node] = min(lowlink[node], lowlink[to[node]]);
	} else if (inS[to[node]])
		lowlink[node] = min(lowlink[node], idx[to[node]]);
	if (lowlink[node] == idx[node]) {
		int cur;
		vector<int> scc;
		do {
			cur = S.top();
			S.pop();
			inS[cur] = 0;
			scc.push_back(cur);
		} while (cur != node);
		components.push_back(scc);
	}
}

int main() {
//#ifndef ONLINE_JUDGE
//	freopen("in.in", "r", stdin);
////	freopen("out.out", "w", stdout);
//#endif

	memset(idx, -1, sizeof idx);
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d%d", &to[i], &p[i]);
	for (int i = 1; i <= n; i++)
		if (!vis[i])
			SCC(i);
	double ans = 0.0;
	for (int i = 0; i < (int) components.size(); i++)
		if ((int) components[i].size() > 1) {
			double temp = 1.0;
			for (int j = 0; j < (int) components[i].size(); j++)
				temp *= p[components[i][j]] / 100.0;
			ans += temp;
		}

	printf("%.2f\n", ans);
	return 0;
}
