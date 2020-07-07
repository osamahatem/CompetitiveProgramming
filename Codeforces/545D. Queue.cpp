/*
 * 545D. Queue.cpp
 *
 *  Created on: May 19, 2015
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

	int n, x, ans = 0;
	long long sum = 0;
	priority_queue<int> Q;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x;
		Q.push(-x);
	}
	while (Q.size()) {
		int cur = -Q.top();
		Q.pop();
		if (sum <= cur) {
			ans++;
			sum += cur;
		}
	}
	cout << ans << endl;
	return 0;
}
