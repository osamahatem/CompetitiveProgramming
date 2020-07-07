/*
 * Elementary Cellular Automaton.cpp
 *
 *  Created on: Oct 18, 2014
 *      Author: Osama Hatem
 */

#include <bits/stdtr1c++.h>
#include <ext/numeric>

using namespace std;

int main() {
#ifndef ONLINE_JUDGE
//	freopen("in.in", "r", stdin);
//	freopen("out.out", "w", stdout);
#endif

	int r, it, n;
	unsigned long long state;
	cin >> r >> it >> n >> state;
	int t = 0;
	while (t < it) {
		printf("%-3d -", ++t);
		for (int i = n - 1; i >= 0; i--)
			cout << (state & (1llu << i) ? "*" : " ");
		cout << "-\n";
		unsigned long long news = 0;
		for (int i = n - 1; i >= 0; i--) {
			int b;
			if (i > 1)
				b = (state >> (i - 1)) % 8;
			else if (i == 1)
				b = state % 8;
			else
				b = (state % 4) * 2;
			news |= ((unsigned long long) (bool) ((1 << b) & r)) << i;
		}
		if (news == state)
			break;
		state = news;
	}
	if (t < it) {
		printf("%-3d -", ++t);
		for (int i = n - 1; i >= 0; i--)
			cout << (state & (1llu << i) ? "*" : " ");
		cout << "-\n";
	}
	return 0;
}
