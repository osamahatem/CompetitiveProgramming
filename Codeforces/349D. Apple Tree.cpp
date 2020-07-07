/*
 * 349D. Apple Tree.cpp
 *
 *  Created on: Dec 25, 2014
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

vector<int> adj[100005];
long long apple[100005], lcm[100005];
int childCnt[100005];
bool vis[100005];

long long DFS(int n) {
	lcm[n] = 1;
	vis[n] = 1;
	long long mini = 1ll << 60;
	for (int i = 0; i < (int) adj[n].size(); i++) {
		if (!vis[adj[n][i]]) {
			mini = min(mini, DFS(adj[n][i]));
			apple[n] += apple[adj[n][i]];
			lcm[n] = lcm[n] * lcm[adj[n][i]] / __gcd(lcm[n], lcm[adj[n][i]]);
			childCnt[n]++;
		}
	}
	if (childCnt[n] == 0)
		return apple[n];
	if (mini == 0 || lcm[n] > apple[n])
		return 0;
	long long ret = mini / lcm[n] * lcm[n];
	lcm[n] *= childCnt[n];
	return ret * childCnt[n];
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n, a, b;
	long long sum = 0;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> apple[i], sum += apple[i];
	for (int i = 1; i < n; i++) {
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	cout << sum - DFS(1) << endl;
	return 0;
}
