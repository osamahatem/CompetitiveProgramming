/*
 * 500C. New Year Book Reading.cpp
 *
 *  Created on: Dec 30, 2014
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

bool vis[505];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n, m, w[505], q[1005], ans = 0;
	vector<int> start;
	stack<pair<int, int> > S, temp;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> w[i];
	for (int i = 0; i < m; i++) {
		cin >> q[i];
		if (!vis[q[i]])
			start.push_back(q[i]), vis[q[i]] = 1;
	}
	while (start.size()) {
		S.push(make_pair(start.back(), w[start.back()]));
		start.pop_back();
	}
	for (int i = 0; i < m; i++) {
		while (S.top().first != q[i]) {
			temp.push(S.top());
			ans += S.top().second;
			S.pop();
		}
		pair<int, int> cur = S.top();
		S.pop();
		while (temp.size()) {
			S.push(temp.top());
			temp.pop();
		}
		S.push(cur);
	}
	cout << ans << endl;
	return 0;
}
