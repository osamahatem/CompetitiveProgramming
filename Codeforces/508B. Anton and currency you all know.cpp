/*
 * 508B. Anton and currency you all know.cpp
 *
 *  Created on: Jan 27, 2015
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

	string n;
	cin >> n;
	int last = (int) n.size() - 1, ans = -(1 << 30), id = -1;
	for (int i = 0; i < last; i++)
		if ((n[i] - '0') % 2 == 0 && ans < 0)
			ans = n[last] - n[i], id = i;
	if (id == -1)
		cout << "-1" << endl;
	else {
		swap(n[last], n[id]);
		cout << n << endl;
	}
	return 0;
}
