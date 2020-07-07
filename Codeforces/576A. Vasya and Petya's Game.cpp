/*
 * 576A. Vasya and Petya's Game.cpp
 *
 *  Created on: Sep 10, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

bool vis[1005];

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n;
	cin >> n;
	vector<int> ans;
	for (int i = 2; i <= n; i++) {
		if (!vis[i]) {
			ans.push_back(i);
			for (int j = i * i; j <= n; j *= i)
				ans.push_back(j);
			for (int j = i * 2; j <= n; j += i)
				vis[j] = 1;
		}
	}
	cout << ans.size() << endl;
	for (int i = 0; i < (int) ans.size(); i++) {
		if (i)
			cout << " ";
		cout << ans[i];
	}
	cout << endl;
	return 0;
}
