/*
 * I. ACM Student Chapter (A).cpp
 *
 *  Created on: Sep 3, 2015
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

	int n;
	cin >> n;
	while (n--) {
		int h, m, s, t1 = 0, t2 = 0;
		char ex;
		cin >> h >> ex >> m >> ex >> s;
		t1 += 3600 * h + 60 * m + s;
		cin >> h >> ex >> m >> ex >> s;
		t2 += 3600 * h + 60 * m + s;
		if (t2 - t1 >= 3 * 3600) {
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;
	return 0;
}
