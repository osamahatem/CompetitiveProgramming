/*
 * J. Balloons Colors.cpp
 *
 *  Created on: Aug 29, 2016
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

string dToB(int x) {
	string ret = "";
	for (int i = 7; i >= 0; i--)
		ret += (x & (1 << i)) ? "1" : "0";
	return ret;
}

int bToD(string x) {
	int ret = 0;
	for (int i = 0; i < 8; i++)
		ret = ret * 2 + x[i] - '0';
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int T;
	scanf("%d", &T);
	while (T--) {
		int r, g, b;
		scanf("%d%d%d", &r, &g, &b);
		string x = dToB(r) + dToB(g) + dToB(b);
		for (int i = 0; i < 12; i++)
			if (x[i] != x[23 - i])
				x[i] = x[23 - i] = '0';
		r = bToD(x.substr(0, 8));
		g = bToD(x.substr(8, 8));
		b = bToD(x.substr(16, 8));
		printf("%03d %03d %03d\n", r, g, b);
	}
	return 0;
}
