/*
 * 456B. Fedya and Maths.cpp
 *
 *  Created on: Aug 8, 2014
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

	string in;
	cin >> in;
	int last = (int) in.size() - 1;
	if (last == 0)
		last++, in = "0" + in;
	int mod = in[last] - '0' + (in[last - 1] - '0') * 10;
	mod %= 4;
	printf("%d\n", (mod == 0 ? 4 : 0));
	return 0;
}
