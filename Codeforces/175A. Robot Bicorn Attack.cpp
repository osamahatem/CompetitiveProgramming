/*
 * 175A. Robot Bicorn Attack.cpp
 *
 *  Created on: Apr 24, 2015
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

const int LIM = 1000000;

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	string in;
	int maxi = -1;
	cin >> in;
	int len = (int) in.size();
	for (int i = 0; i < len; i++) {
		for (int j = i + 1; j < len; j++) {
			int a1 = 0, a2 = 0, a3 = 0, l1 = 0, l2 = 0, l3 = 0;
			for (int k = 0; k <= i; k++)
				a1 = a1 * 10 + in[k] - '0', l1++;
			for (int k = i + 1; k <= j; k++)
				a2 = a2 * 10 + in[k] - '0', l2++;
			for (int k = j + 1; k < len; k++)
				a3 = a3 * 10 + in[k] - '0', l3++;
			if (a1 > LIM || a2 > LIM || a3 > LIM)
				continue;
			if (l1 > 7 || l1 == 0 || l2 > 7 || l2 == 0 || l3 > 7 || l3 == 0)
				continue;
			if ((in[0] == '0' && l1 > 1) || (in[i + 1] == '0' && l2 > 1)
					|| (in[j + 1] == '0' && l3 > 1))
				continue;
			maxi = max(maxi, a1 + a2 + a3);
		}
	}
	cout << maxi << endl;
	return 0;
}
