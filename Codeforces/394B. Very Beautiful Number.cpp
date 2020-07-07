/*
 * 394B. Very Beautiful Number.cpp
 *
 *  Created on: May 8, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int p, x;
string temp2, temp, ans;

bool solve(int d) {
	int carry = 0, last = d;
	temp.clear();
	do {
		temp += '0' + last;
		int res = last * x + carry;
		last = res % 10;
		carry = res / 10;
	} while ((int) temp.size() < p && !(last == d && !carry));
	if (p % (int) temp.size() == 0 && last == d && !carry) {
		temp2.clear();
		reverse(temp.begin(), temp.end());
		if (temp[0] == '0')
			return false;
		while ((int) temp2.size() < p)
			temp2 += temp;
		return true;
	}
	return false;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	cin >> p >> x;
	if (p == 1) {
		if (x == 1)
			cout << "1" << endl;
		else
			cout << "Impossible" << endl;
		return 0;
	}
	bool flag = 0;
	for (int i = 1; i < 10; i++) {
		if (solve(i)) {
			if (!flag)
				ans = temp2;
			else
				ans = min(ans, temp2);
			flag = 1;
		}
	}
	cout << (flag ? ans : "Impossible") << endl;
	return 0;
}
