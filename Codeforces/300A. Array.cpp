/*
 * 300A. Array.cpp
 *
 *  Created on: Nov 30, 2014
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

	int n, c0 = 0, x;
	vector<int> neg, pos;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x;
		if (x == 0)
			c0++;
		else if (x > 0)
			pos.push_back(x);
		else
			neg.push_back(x);
	}
	cout << "1 " << neg[0] << endl;
	cout << pos.size() + ((int) neg.size() - 1) / 2 * 2;
	for (int i = 0; i < (int) pos.size(); i++)
		cout << " " << pos[i];
	for (int i = 1; i + 1 < (int) neg.size(); i += 2)
		cout << " " << neg[i] << " " << neg[i + 1];
	cout << endl;
	if ((int) neg.size() % 2 == 0)
		cout << c0 + 1 << " " << neg.back();
	else
		cout << c0;
	for (int i = 0; i < c0; i++)
		cout << " 0";
	cout << endl;
	return 0;
}
