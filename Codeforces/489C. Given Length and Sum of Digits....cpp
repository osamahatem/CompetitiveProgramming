/*
 * 489C. Given Length and Sum of Digits....cpp
 *
 *  Created on: Jun 20, 2015
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

	int m, s, mini[105], maxi[105], temp;
	cin >> m >> s;
	fill(mini, mini + m, 0);
	fill(maxi, maxi + m, 9);
	if (!s) {
		cout << (m == 1 ? "0 0" : "-1 -1") << endl;
		return 0;
	}
	temp = 1, mini[0] = 1;
	for (int i = m - 1; i >= 0 && temp < s; i--) {
		int add = min(9 - mini[i], s - temp);
		temp += add, mini[i] += add;
	}
	if (temp != s)
		cout << "-1 ";
	else {
		for (int i = 0; i < m; i++)
			cout << mini[i];
		cout << " ";
	}
	temp = 9 * m;
	for (int i = m - 1; i >= 0 && temp > s; i--) {
		int sub = min(9, temp - s);
		temp -= sub, maxi[i] -= sub;
	}
	if (temp != s)
		cout << "-1";
	else
		for (int i = 0; i < m; i++)
			cout << maxi[i];
	cout << endl;
	return 0;
}
