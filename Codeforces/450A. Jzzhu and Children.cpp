/*
 * 450A. Jzzhu and Children.cpp
 *
 *  Created on: Jul 3, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int n, m, arr[105];
	queue<int> Q;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		Q.push(i), cin >> arr[i];
	int ans;
	while (Q.size()) {
		ans = Q.front();
		arr[Q.front()] -= m;
		if (arr[Q.front()] > 0)
			Q.push(Q.front());
		Q.pop();
	}
	cout << ans << endl;
	return 0;
}
