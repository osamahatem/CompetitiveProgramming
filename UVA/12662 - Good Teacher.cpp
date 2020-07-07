/*
 * 12662 - Good Teacher.cpp
 *
 *  Created on: Aug 31, 2014
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

	string name[105];
	int n, q, x;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> name[i];
	cin >> q;
	while (q--) {
		cin >> x;
		x--;
		if (name[x] != "?")
			cout << name[x];
		else {
			int left = x, right = x;
			while (left >= 0 && name[left] == "?")
				left--;
			while (right < n && name[right] == "?")
				right++;
			if (left < 0) {
				while (right > x)
					cout << "left of ", x++;
				cout << name[x];
			} else if (right == n) {
				while (left < x)
					cout << "right of ", x--;
				cout << name[x];
			} else if (right - x == x - left)
				cout << "middle of " << name[left] << " and " << name[right];
			else if (right - x < x - left) {
				while (right > x)
					cout << "left of ", x++;
				cout << name[x];
			} else {
				while (left < x)
					cout << "right of ", x--;
				cout << name[x];
			}
		}
		cout << "\n";
	}
	return 0;
}
