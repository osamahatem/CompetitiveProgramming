/*
 ID: 19semse1
 PROG: lamps
 LANG: C++
 */
/*
 * lamps.cpp
 *
 *  Created on: Mar 10, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

set<string> ans;

int main() {
//#ifndef ONLINE_JUDGE
	freopen("lamps.in", "r", stdin);
	freopen("lamps.out", "w", stdout);
//#endif

	int n, c, x;
	cin >> n >> c;
	string init(n, '1'), final(n, '*');
	while (cin >> x, x != -1)
		final[--x] = '1';
	while (cin >> x, x != -1)
		final[--x] = '0';
	for (int i = 0; i < 16; i++) {
		int cur = i, bits = 0;
		while (cur) {
			bits += cur & 1;
			cur /= 2;
		}
		if (c < bits || (c - bits) % 2)
			continue;
		string temp = init;
		if (i & 1)
			for (int j = 0; j < n; j += 2)
				temp[j] = (temp[j] == '0' ? '1' : '0');
		if (i & 2)
			for (int j = 1; j < n; j += 2)
				temp[j] = (temp[j] == '0' ? '1' : '0');
		if (i & 4)
			for (int j = 0; j < n; j += 3)
				temp[j] = (temp[j] == '0' ? '1' : '0');
		if (i & 8)
			for (int j = 0; j < n; j++)
				temp[j] = (temp[j] == '0' ? '1' : '0');
		bool flag = 1;
		for (int j = 0; j < n; j++)
			if (final[j] != '*' && temp[j] != final[j])
				flag = 0;
		if (flag)
			ans.insert(temp);
	}
	if (!ans.size())
		cout << "IMPOSSIBLE" << endl;
	else
		for (set<string>::iterator it = ans.begin(); it != ans.end(); it++)
			cout << *it << endl;
	return 0;
}
