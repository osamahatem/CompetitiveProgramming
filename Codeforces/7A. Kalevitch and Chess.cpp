/*
 * 7A. Kalevitch and Chess.cpp
 *
 *  Created on: Aug 30, 2015
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

	char row[10];
	set<int> r, c;
	for (int i = 0; i < 8; i++) {
		cin >> row;
		for (int j = 0; j < 8; j++)
			if (row[j] == 'W')
				r.insert(i), c.insert(j);
	}
	int ans = 16 - (int) r.size() - (int) c.size();
	if (ans == 16)
		ans = 8;
	cout << ans << endl;
	return 0;
}
