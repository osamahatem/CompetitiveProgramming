/*
 * E. Elvis Presley.cpp
 *
 *  Created on: Apr 15, 2018
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

	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int a, b;
	cin >> a >> b;

	int ta = a, tb = b;
	while (ta != tb) {
		if (ta > tb)
			ta /= 2;
		else
			tb /= 2;
	}
	int lca = ta;
	if (lca == a || lca == b)
		cout << "-1" << endl;
	else {
		set<int> ans;
		ans.insert(a), ans.insert(b);
		while (a / 2 > lca) {
			ans.insert(a ^ 1);
			a /= 2;
		}
		while (b / 2 > lca) {
			ans.insert(b ^ 1);
			b /= 2;
		}
		while (lca > 1) {
			ans.insert(lca ^ 1);
			lca /= 2;
		}
		for (auto it = ans.begin(); it != ans.end(); it++) {
			if (it != ans.begin())
				cout << " ";
			cout << *it;
		}
		cout << endl;
	}
	return 0;
}
