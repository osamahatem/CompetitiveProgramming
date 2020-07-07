/*
 * Delivery System.cpp
 *
 *  Created on: Sep 19, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 1e5 + 5;
const int MAXE = 2e5 + 5;

int head[MAXN], nxt[MAXE], to[MAXE], last;
int component[MAXN], lowlink[MAXN], idx[MAXN], _idx, comps;
bool inS[MAXN], need[MAXN];
int dp[MAXN], path[MAXN];
stack<int> S;
vector<vector<int>> kPerComp;

void addEdge(int f, int t) {
	to[last] = t;
	nxt[last] = head[f];
	head[f] = last++;
}

void SCC(int node) {
	lowlink[node] = idx[node] = _idx++;
	S.push(node), inS[node] = 1;
	for (int i = head[node]; i != -1; i = nxt[i])
		if (idx[to[i]] == -1) {
			SCC(to[i]);
			lowlink[node] = min(lowlink[node], lowlink[to[i]]);
		} else if (inS[to[i]])
			lowlink[node] = min(lowlink[node], idx[to[i]]);
	if (lowlink[node] == idx[node]) {
		int cur;
		kPerComp.push_back(vector<int>());
		do {
			cur = S.top();
			S.pop();
			inS[cur] = 0;
			component[cur] = comps;
			if (need[cur])
				kPerComp[comps].push_back(cur);
		} while (cur != node);
		sort(kPerComp[comps].begin(), kPerComp[comps].end());
		comps++;
	}
}

int solve(int n) {
	int &ret = dp[n];
	if (ret != -1)
		return ret;
	ret = 0;
	for (int i = head[n]; i != -1; i = nxt[i])
		if (component[n] != component[to[i]]) {
			int temp = solve(to[i]);
			if (temp > ret)
				ret = temp, path[n] = to[i];
		}
	ret += kPerComp[component[n]].size();
	return ret;
}

int main() {
//#ifndef ONLINE_JUDGE
//	freopen("in.in", "r", stdin);
////	freopen("out.out", "w", stdout);
//#endif

	int T;
	scanf("%d", &T);
	while (T--) {
		memset(head, -1, sizeof head), last = 0;
		memset(idx, -1, sizeof idx), _idx = 0, comps = 0;
		memset(need, 0, sizeof need);
		memset(path, 0, sizeof path);
		memset(dp, -1, sizeof dp);
		kPerComp.clear();
		int n, m, k, x, y;
		scanf("%d%d%d", &n, &m, &k);
		for (int i = 0; i < k; i++) {
			scanf("%d", &x);
			need[x] = 1;
		}
		while (m--) {
			scanf("%d%d", &x, &y);
			addEdge(x, y);
		}
		for (int i = 1; i <= n; i++)
			if (idx[i] == -1)
				SCC(i);
		bool flag = 0;
		for (int i = 1; i <= n; i++) {
			if (dp[i] == -1) {
				int temp = solve(i);
				if (temp == k) {
					flag = 1;
					vector<int> ans;
					int cur = i;
					while (cur) {
						for (int j = 0;
								j < (int) kPerComp[component[cur]].size(); j++)
							ans.push_back(kPerComp[component[cur]][j]);
						cur = path[cur];
					}
					for (int j = 0; j < (int) ans.size(); j++) {
						if (j)
							printf(" ");
						printf("%d", ans[j]);
					}
					printf("\n");
					break;
				}
			}
		}
		if (!flag)
			printf("-1\n");
	}
	return 0;
}
