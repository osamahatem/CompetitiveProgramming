/*
 * 494C. Helping People.cpp
 *
 *  Created on: Aug 15, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

struct node {
	int a, b;
	double p;

	const bool operator <(const node& other) const {
		if (a != other.a)
			return a < other.a;
		return b > other.b;
	}
};

int n, q, arr[100000], maxInQ[5001], cur;
node Q[5001];
bool vis[5001][5001];
double dp[5001][5001];
vector<int> adj[5001];

double solve(int idx, int left) {
	if (vis[idx][left])
		return dp[idx][left];
	vis[idx][left] = 1;
	double ret = 1.0 - Q[idx].p;
	for (int i = 0; i < (int) adj[idx].size(); i++) {
		int to = adj[idx][i];
		ret *= solve(to, min(q, left + maxInQ[idx] - maxInQ[to]));
	}
	if (left) {
		double temp = Q[idx].p;
		for (int i = 0; i < (int) adj[idx].size(); i++) {
			int to = adj[idx][i];
			temp *= solve(to, min(q, left + maxInQ[idx] - maxInQ[to] - 1));
		}
		ret += temp;
	}
	return dp[idx][left] = ret;
}

int preCompute(int idx) {
	cur++;
	int last = Q[idx].a;
	while (cur <= q && Q[cur].b <= Q[idx].b) {
		while (last < Q[cur].a)
			maxInQ[idx] = max(maxInQ[idx], arr[last++]);
		last = Q[cur].b + 1;
		adj[idx].push_back(cur);
		maxInQ[idx] = max(maxInQ[idx], preCompute(cur));
	}
	while (last <= Q[idx].b)
		maxInQ[idx] = max(maxInQ[idx], arr[last++]);
	return maxInQ[idx];
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	scanf("%d%d", &n, &q);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	for (int i = 0; i < q; i++) {
		scanf("%d%d%lf", &Q[i].a, &Q[i].b, &Q[i].p);
		Q[i].a--, Q[i].b--;
	}
	Q[q].a = 0, Q[q].b = n - 1, Q[q].p = 0.0;
	sort(Q, Q + q + 1);
	preCompute(0);
	double ans = 0.0, last = 0.0;
	for (int i = 0; i <= q; i++) {
		double temp = solve(0, i);
		ans += 1.0 * (maxInQ[0] + i) * (temp - last);
		last = temp;
	}
	printf("%.6f\n", ans);
	return 0;
}
