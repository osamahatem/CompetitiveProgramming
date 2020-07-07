/*
 * 510E. Fox And Dinner.cpp
 *
 *  Created on: Feb 4, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 205;
const int MAXE = 2 * MAXN * MAXN;
const int SRC = MAXN - 1;
const int SNK = MAXN - 2;

int head[MAXN], to[MAXE], cap[MAXE], nxt[MAXE], last;
int arr[MAXN], vis[MAXN], id;
vector<vector<int> > out;

void addEdge(int f, int t, int c) {
	to[last] = t;
	cap[last] = c;
	nxt[last] = head[f];
	head[f] = last++;
}

void addAugEdge(int f, int t, int c) {
	addEdge(f, t, c);
	addEdge(t, f, 0);
}

bool isPrime(int x) {
	for (int i = 2; i * i <= x; i++)
		if (x % i == 0)
			return false;
	return true;
}

bool dfs(int n) {
	if (n == SNK)
		return true;
	vis[n] = id;
	for (int i = head[n]; i != -1; i = nxt[i]) {
		int t = to[i];
		if (vis[t] == id || !cap[i])
			continue;
		if (dfs(t)) {
			cap[i]--, cap[i ^ 1]++;
			return true;
		}
	}
	return false;
}

int maxFlow() {
	int ans = 0;
	while (id++, dfs(SRC))
		ans++;
	return ans;
}

void getOut(int n) {
	vis[n] = id;
	int last = (int) out.size() - 1;
	out[last].push_back(n + 1);
	for (int i = head[n]; i != -1; i = nxt[i]) {
		int t = to[i];
		if (vis[t] == id || t == SRC || t == SNK)
			continue;
		if ((arr[n] % 2 && !cap[i]) || (arr[n] % 2 == 0 && cap[i] == 1))
			getOut(t);
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	memset(head, -1, sizeof head);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		if (arr[i] % 2)
			addAugEdge(SRC, i, 2);
		else
			addAugEdge(i, SNK, 2);
	}
	for (int i = 0; i < n; i++) {
		if (arr[i] % 2 == 0)
			continue;
		for (int j = 0; j < n; j++)
			if (isPrime(arr[i] + arr[j]))
				addAugEdge(i, j, 1);
	}
	int ans = maxFlow();
	if (ans < n) {
		cout << "Impossible" << endl;
		return 0;
	}
	id++;
	for (int i = 0; i < n; i++)
		if (vis[i] != id)
			out.push_back(vector<int>()), getOut(i);
	cout << out.size() << endl;
	for (int i = 0; i < (int) out.size(); i++) {
		cout << out[i].size();
		for (int j = 0; j < (int) out[i].size(); j++)
			cout << " " << out[i][j];
		cout << endl;
	}
	return 0;
}
