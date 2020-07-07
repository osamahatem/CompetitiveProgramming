/*
 * 520B. Two Buttons.cpp
 *
 *  Created on: Mar 3, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int MAXN = 2e4 + 5;

int tar;
bool vis[MAXN];

int BFS(int n) {
	queue<int> Q;
	Q.push(n);
	int ans = -1;
	bool flag = 0;
	while (!flag) {
		ans++;
		int sz = Q.size();
		while (sz--) {
			int cur = Q.front();
			Q.pop();
			if (cur == tar) {
				flag = 1;
				break;
			}
			if (vis[cur] || !cur)
				continue;
			vis[cur] = 1;
			if (cur < tar)
				Q.push(cur * 2);
			Q.push(--cur);
		}
	}
	return ans;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n;
	cin >> n >> tar;
	cout << BFS(n) << endl;
	return 0;
}
