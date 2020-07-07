/*
 * 471A. MUH and Sticks.cpp
 *
 *  Created on: Aug 2, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int cnt[10], x;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	bool legs = 0;
	vector<int> v;
	for (int i = 0; i < 6; i++) {
		cin >> x;
		cnt[x]++;
		if (cnt[x] == 4)
			legs = 1, cnt[x] = 0;
	}
	if (!legs) {
		cout << "Alien" << endl;
		return 0;
	}
	for (int i = 1; i < 10; i++)
		while (cnt[i]) {
			v.push_back(i);
			cnt[i]--;
		}
	cout << (v[0] == v[1] ? "Elephant" : "Bear") << endl;
	return 0;
}
